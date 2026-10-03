#pragma once

#include <basis/seadTypes.h>
#include <container/seadListImpl.h>
#include <container/seadSafeArray.h>
#include <math/seadMathCalcCommon.h>
#include <prim/seadBitFlag.h>
#include <prim/seadRuntimeTypeInfo.h>
#include <prim/seadSafeString.h>
#include <prim/seadTypedBitFlag.h>
#include <thread/seadAtomic.h>
#include "KingSystem/ActorSystem/actBaseProcJob.h"
#include "KingSystem/ActorSystem/actBaseProcMap.h"
#include "KingSystem/Utils/Container/StrTreeMap.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class ActorLinkConstDataAccess;
class BaseProc;
class BaseProcLinkData;
class BaseProcJobHandler;
class BaseProcUnit;

/// Actor base class that encapsulates all the low-level actor lifetime logic.
class BaseProc {
public:
    enum class State : u8 {
        /// The actor is constructed, but not fully initialized yet.
        Init = 0,
        /// The actor is active.
        Calc = 1,
        /// The actor is sleeping: its update jobs won't be run.
        Sleep = 2,
        /// The actor is scheduled for deletion.
        Delete = 3,
    };

    enum class DeleteReason : u32 {
        Default = 0,
        InitFailed = 1,
        ProcUnitReleased = 2,
        BaseProcMgrDeleteAll = 4,
        CreateLinkObjRevival = 6,
        DeleteLinkObjRevival = 7,
        ObjectLinkDelete = 8,
        GodForestOff = 9,
        _a = 0xa,
        OutOfDeleteDistance = 0xb,
        OutOfLoadDistance = 0xc,
        _d = 0xd,
        FadeoutDeleteBeforeWake = 0xe,
        ActorLimiter = 0xf,
        PreActorHandedOver = 0x10,
        CreateFailed = 0x11,
        DebugReloadPlacement = 0x12,
        DebugUnloadByName = 0x13,
        NotFarActor = 0x15,
        ConnectedCalcChildDeleted = 0x16,
        ConnectedCalcParentDeleted = 0x17,
        ConnectedCalcChildNewDeleted = 0x18,
        ConnectedCalcParentNewDeleted = 0x19,
        HorseEquipment = 0x1a,
        EventOffWaitRevival = 0x1d,
    };

    enum class SleepWakeReason : u32 {
        Default = 0,
        VillagerMgr = 1,
    };

    struct ClassInfo {
        sead::SafeString name;
        u8 priority;
    };
    KSYS_CHECK_SIZE_NX150(ClassInfo, 0x18);

    struct CreateArg {
        const ClassInfo* class_info;
        void* _8;
        u32 _10;
        u32 _14;
        sead::SafeString actor_name;
    };
    KSYS_CHECK_SIZE_NX150(CreateArg, 0x28);

    struct PreDeleteArg {
        bool do_not_destruct_immediately = false;
    };

    explicit BaseProc(const CreateArg& arg);
    virtual ~BaseProc();

    SEAD_RTTI_BASE(BaseProc)

    /// @return true iff state is Calc and the actor is not being deleted.
    bool init(sead::Heap* heap, bool sleep_after_init);
    /// Put this actor to sleep. The request is queued.
    void sleep(SleepWakeReason reason);
    /// Wake up this actor. The request is queued.
    void wakeUp(SleepWakeReason reason);
    /// Delete this actor. The request is queued.
    bool deleteLater(DeleteReason reason);
    void freeLinkData();

    u32 getId() const { return mId; }
    const sead::SafeString& getName() const { return mName; }

    u8 getPriority() const { return mPriority; }
    void setPriority(u8 priority) { mPriority = priority; }

    State getState() const { return mState; }
    bool isInit() const { return mState == State::Init; }
    bool isCalc() const { return mState == State::Calc; }
    bool isSleep() const { return mState == State::Sleep; }
    bool isDelete() const { return mState == State::Delete; }
    bool isDeletedOrDeleting() const {
        return mState == State::Delete || mStateFlags.isOn(StateFlags::RequestDelete);
    }
    bool isDeleteOrInvalid() const { return mState >= act::BaseProc::State::Delete; }

    /// For BaseProcLink or ActorLinkConstDataAccess.
    bool acquire(ActorLinkConstDataAccess& accessor);
    BaseProcLinkData* getBaseProcLinkData() const { return mBaseProcLinkData; }
    /// For BaseProcLink or ActorLinkConstDataAccess.
    void release();

    BaseProc* getConnectedCalcParent() const;
    bool setConnectedCalcParent(BaseProc* parent, bool delete_parent_on_delete);
    void resetConnectedCalcParent(bool clear_existing_set_request);

    BaseProc* getConnectedCalcChild() const;
    bool setConnectedCalcChild(BaseProc* child, bool delete_child_on_delete);
    void resetConnectedCalcChild(bool clear_existing_set_request);

    bool isJobTypePaused(JobType type);
    bool shouldSkipJobPush(JobType type);
    void setJobPriority(u8 priority, JobType type);
    void setJobSubPriority(u8 sub_priority, JobType type);

    void setCreatePriorityState1();
    void setCreatePriorityState2();

    void onJobPush(JobType type) {
        onJobPush1_(type);
        onJobPush2_(type);
    }

    /// Actually pre-delete the actor. Called from BaseProcDeleter.
    void doPreDelete(const PreDeleteArg& arg);

    /// Set the BaseProcUnit. Only for use by BaseProcCreateTask.
    void setUnitForBaseProcCreateTask(BaseProcUnit* unit) { mProcUnit = unit; }
    void setInitializedFlag() { mFlags.set(Flags::Initialized); }
    bool requestDeleteProcUnit() { return setStateFlag(StateFlags::RequestDeleteProcUnit); }

    bool isInitialized() const { return mFlags.isOn(Flags::Initialized); }
    bool isDeleting() const { return mFlags.isOn(Flags::PreDeleteStarted); }
    bool isDeleteRequested() const { return mStateFlags.isOn(StateFlags::RequestDelete); }

protected:
    friend class BaseProcLinkDataMgr;
    friend class BaseProcMgr;

    enum class Flags : u32 {
        Initialized = 1,
        PreDeleteStarted = 2,
        PreDeleteFailed = 4,
        Destructed = 8,
        /// Set via the "@SB" create param (resident/system actors).
        DoNotDelete = 0x10,
        DeleteChildOnDelete = 0x20,
        DeleteParentOnDelete = 0x40,
        WakeUpCheckCached = 0x80,
        WakeUpCheckResult = 0x100,
        PreDeleting = 0x200,
        SleepWakeReason0 = 0x400,
        SleepWakeReason1 = 0x800,
        SleepWakeReason2 = 0x1000,
        SleepWakeReason3 = 0x2000,
        SleepWakeReasonAny =
            SleepWakeReason0 | SleepWakeReason1 | SleepWakeReason2 | SleepWakeReason3,
    };

    enum class StateFlags : u32 {
        RequestDelete = 1,
        /// Only ever tested together with RequestWakeUp; never set.
        _2 = 2,
        RequestSleep = 4,
        RequestWakeUp = 8,
        _a = _2 | RequestWakeUp,
        RequestChangeCalcJobPriority = 0x10,
        _20 = 0x20,  // unused
        _40 = 0x40,  // unused
        _80 = 0x80,  // unused
        RequestSetParent = 0x100,
        RequestSetChild = 0x200,
        RequestResetParent = 0x400,
        RequestResetChild = 0x800,
        _1000 = 0x1000,  // unused
        _2000 = 0x2000,  // unused
        /// Never set in 1.5.0.
        KeepInUpdateStateList = 0x4000,
        RequestDeleteProcUnit = 0x8000,
    };

    enum class InitResult : u32 {
        Ok = 1,
        Failed = 2,
        Skipped = 3,
    };

    enum class PreDeletePrepareResult : u32 {
        NotDone = 0,
        Done = 1,
    };

    enum class JobPauseState {
        NotPaused = 0,
        Paused = 1,
        PausedSelfOnly = 2,
    };

    struct InitContext {
        InitResult result;
        bool sleep_after_init;
    };

    struct PrepareArg {
        bool _0 = false;
        int _4;
    };

    /// Initialize the actor.
    /// @return Ok to keep the actor alive, anything else to kill it.
    virtual InitResult init_();
    /// @return whether prepareInit_ and init_ should be called.
    virtual bool shouldInit_();
    /// Finalize the initialization; the actor is deleted if the result is not Ok.
    virtual void finalizeInit_(InitContext* context);

    /// Called once prepareForPreDelete_ returns true. Return Done to request the pre-delete.
    virtual PreDeletePrepareResult finishPreparingForPreDelete_();
    /// Polled every frame until it returns true.
    virtual bool prepareForPreDelete_();

    /// Destructs this actor if should_destruct is 1.
    /// @warning The actor must NOT be used after calling this function.
    virtual void destruct_(int should_destruct);

    /// Called when entering the Calc state.
    virtual void onEnterCalc_();

    /// Called when a new delete operation is queued.
    virtual void onDeleteRequested_(DeleteReason reason);
    /// Called when a new sleep operation is queued.
    virtual void onSleepRequested_(SleepWakeReason reason);
    /// Called when a new wakeup operation is queued.
    virtual void onWakeUpRequested_(SleepWakeReason reason);

    virtual bool shouldStopKeepingInUpdateStateList_() { return true; }

    /// Called when entering the Delete state.
    virtual void onEnterDelete_();
    /// Called when entering the Sleep state.
    virtual void onEnterSleep_();

    /// Third and final pre-delete callback.
    virtual void freeResources_(const PreDeleteArg& arg);

    virtual bool prepareInit_(sead::Heap* heap, PrepareArg& arg);

    /// Called when pre-delete actually starts (after preparation, before requesting it).
    virtual void onPreDeleteStart_(PrepareArg&);
    /// Second pre-delete callback: frees what prepareInit_ allocated.
    virtual void freePrepareInit_(const PreDeleteArg& arg);
    /// First pre-delete callback. Empty in every 1.5.0 implementation.
    virtual void preDelete1_();

    virtual JobPauseState getJobPauseState_(JobType type);
    virtual bool canWakeUp_();
    virtual void carryOverJobRequest_(JobType type, int new_array_idx);
    virtual bool hasJobType_(JobType type);
    /// Called after processStateUpdate() is called for all actors in the update state list.
    virtual void afterUpdateState_();

    virtual bool shouldSkipJobPush_(JobType type);
    /// Called just before shouldSkipJobPush for each job push (first callback).
    virtual void onJobPush1_(JobType type);
    /// Called just before shouldSkipJobPush for each job push (second and final callback).
    virtual void onJobPush2_(JobType type);

    bool processStateUpdate(u8 update_counter);
    void processPreDelete();
    void startDelete_();

    /// Called from BaseProcMgr when a job for this process is invoked.
    void jobInvoked(JobType type);

    bool isJobTypePausedForThisProc_(JobType type) const {
        return mPausedJobTypesMask.isOnBit(int(type));
    }

    BaseProcJobHandler*& getJobHandler(JobType type) { return mJobHandlers[int(type)]; }
    BaseProcJobHandler* getJobHandler(JobType type) const { return mJobHandlers[int(type)]; }

    bool setStateFlag(u32 flag_bit);
    bool setStateFlag(StateFlags flag) { return setStateFlag(sead::log2(u32(flag))); }

    bool willWakeUpThisPass();

    sead::FixedSafeString<64> mName;
    u32 mId = -1;
    State mState = State::Init;
    u8 mPriority = 0;
    u8 mCreatePriorityState = 0;
    u8 mCalcLinkUpdateCounter = 0;
    BaseProcLinkData* mBaseProcLinkData = nullptr;
    sead::BitFlag16 mSkippedJobTypesMask;
    sead::BitFlag16 mPausedJobTypesMask;
    sead::TypedBitFlag<Flags, sead::Atomic<u32>> mFlags;
    sead::TypedBitFlag<StateFlags, sead::Atomic<u32>> mStateFlags;
    BaseProc* mConnectedCalcParent = nullptr;
    BaseProc* mConnectedCalcChild = nullptr;
    BaseProc* mConnectedCalcParentNew = nullptr;
    BaseProc* mConnectedCalcChildNew = nullptr;
    sead::SafeArray<BaseProcJobHandler*, 7> mJobHandlers{};
    sead::Delegate1R<BaseProc, void*, bool> mInvoker;
    sead::ListNode mPreDeleteListNode;
    sead::ListNode mUpdateStateListNode;
    BaseProcMapNode mMapNode{this};
    BaseProcUnit* mProcUnit = nullptr;
    sead::Atomic<s32> mRefCount = 0;

private:
    void unlinkProcUnit_();
    void unlinkCalcChild_();
    void unlinkCalcParent_();
    void loadNewCalcChild_(u8 counter);
    void loadNewCalcParent_(u8 counter);

    void handleSleepRequest_();
    void handleWakeUpRequest_();
    void handleJobPriorityChangeRequest_();

    void setJobPriorityDuringCalc_(BaseProcJobHandler*& handler, JobType type);

    bool canWakeUpCached_() {
        return mFlags.isOn(Flags::WakeUpCheckCached) ? mFlags.isOn(Flags::WakeUpCheckResult) :
                                                       canWakeUp_();
    }
};
KSYS_CHECK_SIZE_NX150(BaseProc, 0x180);

}  // namespace ksys::act
