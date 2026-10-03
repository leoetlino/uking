#pragma once

#include <container/seadBuffer.h>
#include <container/seadOffsetList.h>
#include <container/seadPtrArray.h>
#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <prim/seadBitFlag.h>
#include <prim/seadScopedLock.h>
#include <prim/seadSizedEnum.h>
#include <prim/seadTypedBitFlag.h>
#include <thread/seadAtomic.h>
#include <thread/seadCriticalSection.h>
#include <utility/aglAtomicPtrArray.h>
#include "KingSystem/ActorSystem/actBaseProc.h"
#include "KingSystem/ActorSystem/actBaseProcJob.h"
#include "KingSystem/ActorSystem/actBaseProcMap.h"
#include "KingSystem/Utils/Container/StrTreeMap.h"
#include "KingSystem/Utils/Thread/Task.h"
#include "KingSystem/Utils/Types.h"

namespace sead {
class FixedSizeJQ;
class WorkerMgr;
}  // namespace sead

namespace ksys::act {

class ActorParam;
class BaseProcCreateTaskData;
class BaseProcDeleter;
class BaseProcInitializer;
struct BaseProcInitializerArgs;
class BaseProcJobLists;
class BaseProcJobQue;

struct BaseProcCreateRequest {
    u32 task_lane_id;
    BaseProcCreateTaskData* task_data;
    TaskRemoveCallback* task_remove_callback;
};

class BaseProcMgr {
    SEAD_SINGLETON_DISPOSER(BaseProcMgr)
    BaseProcMgr();

public:
    enum class Status : u8 {
        Idle = 0,
        _1 = 1,
        ProcessingActorJobs = 2,
        ProcessingPreDeleteList = 3,
        ProcessingUpdateStateList = 4,
    };

    enum class PauseMode : u8 {
        None = 0,
        Paused = 1,
        StageLoad = 4,
        SystemPause = 5,
    };

    enum class ProcFilter {
        Sleeping = 1 << 0,
        DeletedOrDeleting = 1 << 1,
        Initializing = 1 << 2,
        SkipAccessCheck = 1 << 3,
        _10 = 1 << 4,
        Deleting = 1 << 5,
        Uninitialized = 1 << 6,
    };

    using ProcFilters = sead::TypedBitFlag<ProcFilter>;
    using JobRequestArray = agl::utl::FixedPtrArray<BaseProcJobLink, 512>;

    /// Wrapper to simplify BaseProc iteration.
    class ProcIteratorContext {
    public:
        ProcIteratorContext(BaseProcMgr& mgr, ProcFilters filters)
            : mMgr(mgr), mCS(mgr.lockProcMap()), mFilters(filters) {}
        ~ProcIteratorContext() { mMgr.unlockProcMap(); }
        BaseProc* next() { return mProc = mMgr.getNextProc(mCS, mProc, mFilters); }

    private:
        BaseProcMgr& mMgr;
        sead::CriticalSection* mCS{};
        ProcFilters mFilters{};
        BaseProc* mProc{};
    };

    static u32 getPreCalcJobType() { return sPreCalcJobType; }
    static u32 getPostBgJobType() { return sPostBgJobType; }
    static u32 getPostSensorJobType() { return sPostSensorJobType; }
    static u32 getFrameEndJobType() { return sFrameEndJobType; }

    virtual ~BaseProcMgr();

    void init(sead::Heap* heap, s32 num_job_types, u32 main_thread_id, u32 worker_thread_id1,
              u32 worker_thread_id2, const BaseProcInitializerArgs& initializer_args);

    // region BaseProc management

    void generateProcId(u32* id);
    void registerProc(BaseProc& proc);
    void unregisterProc(BaseProc& proc);

    void addToPreDeleteList(BaseProc& proc);
    /// @return whether the flag was not set prior to this call and is now set.
    bool setProcFlag(BaseProc& proc, BaseProc::StateFlags flag);
    /// @return whether the flag was not set prior to this call and is now set.
    bool setProcFlag(BaseProc& proc, u32 flag_bit);
    void eraseFromPreDeleteList(BaseProc& proc);
    void eraseFromUpdateStateList(BaseProc& proc);
    void processPreDeleteList();

    // endregion

    bool requestPreDelete(BaseProc& proc);
    void requestUnloadActorParam(ActorParam* param);

    // region Job processing

    void pushJob(BaseProc& proc, JobType type);
    void pushJobs(BaseProc& proc);
    void eraseJob(BaseProc& proc, JobType type);
    void eraseJobs(BaseProc& proc);

    void invokeJobsDirectly(JobType type, s32 prio, bool invoke_requested_jobs);
    JobRequestArray& getCurrentJobRequests();
    void swapJobRequestArrays();

    void requestJob(BaseProcJobLink* job_link);
    void carryOverJobRequests(JobType type);
    bool isJobRequested(BaseProcJobLink* job_link, s32 array_idx);
    void clearJobRequests();

    void pushJobQueues(sead::WorkerMgr* mgr, JobType type, bool skip_access_check);
    bool enqueueJobs(sead::FixedSizeJQ* jq, JobType type, u8 priority, bool begin_phase,
                     bool skip_access_check);
    bool enqueueJobRequests(sead::FixedSizeJQ* jq, JobRequestArray* requests);
    bool enqueueMoreJobs(sead::FixedSizeJQ* jq, JobType type, u8 prio, bool begin_phase,
                         bool skip_access_check);

    void setJobType(JobType type);
    void setActorJobTypeAndPrio(JobType type, s32 prio, bool skip_access_check);
    void goIdle();
    void calc();
    void clearPauseMode();
    sead::CriticalSection* lockProcMap();
    void unlockProcMap();
    void deleteAllProcs();
    bool hasFinishedDeletingAllProcs();
    void jobInvoked(BaseProcJobLink* link, s32 num_procs);

    // endregion

    // region Special job types

    bool isJobTypePaused(JobType type) const;
    void pauseJobTypes(u16 mask);
    void resumeJobTypes(u16 mask);

    // endregion

    /// Returns true if and only if the calling thread is the game thread or a Havok thread.
    bool isHighPriorityThread() const;
    /// Returns true if and only if it is safe to access the specified BaseProc.
    bool isAccessingProcSafe(BaseProc* proc, BaseProc* other) const;

    // region BaseProc creation

    bool requestCreateProc(const BaseProcCreateRequest& req);
    BaseProc* createProc(const BaseProcCreateRequest& req);

    // endregion

    // region BaseProc iteration

    BaseProc* getNextProc(sead::CriticalSection* cs, BaseProc* current_proc, ProcFilters filters);
    /// Get the first BaseProc with the specified name (subject to filters).
    BaseProc* getProc(const sead::SafeString& name, ProcFilters filters);
    /// Get the first BaseProc with the specified ID (subject to filters).
    BaseProc* getProc(const u32& id, ProcFilters filters);
    /// Execute a callback for every process (subject to filters).
    void forEachProc(sead::IDelegate1<BaseProc*>& callback, ProcFilters filters);
    /// Execute a callback for every process with the specified name (subject to filters).
    void forEachProc(const sead::SafeString& proc_name, sead::IDelegate1<BaseProc*>& callback,
                     ProcFilters filters);
    ProcIteratorContext getProcs(ProcFilter filters) { return {*this, filters}; }
    bool checkFilters(BaseProc* proc, ProcFilters filters) const;

    // endregion

    // region Actor initializer control

    bool areInitializerThreadsIdle() const;
    void waitForInitializerQueueToEmpty();
    void cancelInitializerTasks();
    void blockInitializerTasks();
    void restartInitializerThreads();
    void pauseInitializerThreads();
    void resumeInitializerThreads();
    void unblockInitDeleteTasks();
    void pauseInitializerMainThread();
    void resumeInitializerMainThread();
    bool isAnyInitializerThreadActive() const;
    int getInitializerQueueSize() const;
    int getInitializerQueueSizeEx(int x = -1) const;
    void removeInitializerTasksIf(sead::IDelegate1R<Task*, bool>& predicate);
    void setActorGenerationEnabled(bool enabled);

    // endregion

    auto getStageUnloadDepth() const { return mStageUnloadDepth; }
    void incrementStageUnloadDepth();
    void decrementStageUnloadDepth();

    void writeResidentActorsCsv(const sead::SafeString& file_path);

    auto& getProcUpdateStateListCS() { return mProcUpdateStateListCS; }

    void incrementPendingDeletions() { mNumPendingDeletions.increment(); }
    void decrementPendingDeletions() { mNumPendingDeletions.decrement(); }

    Status getStatus() const { return mStatus; }
    JobType getJobType() const { return mJobType; }
    u32 getNumJobTypes() const { return mJobLists.size(); }
    BaseProcJobLists& getJobLists(JobType type) { return mJobLists[u32(type)]; }
    bool isPushingJobs() const { return mIsPushingJobs; }

    static u32 sPreCalcJobType;
    static u32 sPostBgJobType;
    static u32 sPostSensorJobType;
    static u32 sFrameEndJobType;

private:
    void doAddToUpdateStateList_(BaseProc& proc);

    bool canPushJobs() const;

    static sead::BufferedSafeString* sResidentActorListStr;

    Status mStatus = Status::Idle;
    sead::SizedEnum<JobType, u8> mJobType = JobType::Invalid;
    u8 mCurrentlyProcessingPrio = 8;
    u8 mStateUpdateCounter = 0;
    sead::CriticalSection mProcMapCS;
    sead::OffsetList<BaseProc> mProcPreDeleteList;
    sead::Buffer<BaseProcJobLists> mJobLists;
    BaseProcMap mProcMap;
    sead::OffsetList<BaseProc> mProcUpdateStateList;
    sead::CriticalSection mProcUpdateStateListCS;
    sead::CriticalSection mProcPreDeleteListCS;
    BaseProcMapNode* mLastProcMapNode = nullptr;
    BaseProcJobQue* mProcJobQue = nullptr;
    sead::Atomic<u32> mCreatedProcCounter = 0;
    sead::Atomic<u32> mNumPendingDeletions = 0;
    BaseProcInitializer* mProcInitializer = nullptr;
    BaseProcDeleter* mProcDeleter = nullptr;
    bool mIsPushingJobs = false;
    sead::Atomic<bool> mRepeatJobPassRequested = false;
    bool mJobPushEnabled = false;
    PauseMode mPauseMode = PauseMode::None;
    bool mSkipAccessCheck = false;
    bool mIsInitializingQuestMgr = false;
    s8 mCurrentJobRequestArrayIdx = 0;
    u8 mStageUnloadDepth = 0;
    sead::BitFlag16 mPausedJobTypesMask = 0;
    u32 mMainThreadId = 0;
    u32 mWorkerThreadId1 = 0;
    u32 mWorkerThreadId2 = 0;
    u32 mJobPushSuspended = 0;
    sead::SafeArray<JobRequestArray, 2> mJobRequestArrays{};
};
KSYS_CHECK_SIZE_NX150(BaseProcMgr, 0x21a0);

constexpr auto operator|(BaseProcMgr::ProcFilter a, BaseProcMgr::ProcFilter b) {
    return BaseProcMgr::ProcFilter(u32(a) | u32(b));
}

inline bool BaseProcMgr::setProcFlag(BaseProc& proc, BaseProc::StateFlags flag) {
    auto lock = sead::makeScopedLock(mProcUpdateStateListCS);
    doAddToUpdateStateList_(proc);
    return proc.mStateFlags.set(flag);
}

inline bool BaseProcMgr::setProcFlag(BaseProc& proc, u32 flag_bit) {
    auto lock = sead::makeScopedLock(mProcUpdateStateListCS);
    doAddToUpdateStateList_(proc);
    return proc.mStateFlags.getStorage().setBitOn(flag_bit);
}

}  // namespace ksys::act
