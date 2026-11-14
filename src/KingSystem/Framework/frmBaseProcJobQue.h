#pragma once

#include <array>
#include <basis/seadTypes.h>
#include <container/seadSafeArray.h>
#include <mc/seadJob.h>
#include <mc/seadJobQueue.h>
#include <thread/seadAtomic.h>
#include <utility/aglAtomicPtrArray.h>
#include "KingSystem/Framework/frmBaseProcMgrJob.h"
#include "KingSystem/Utils/Types.h"

namespace sead {
class WorkerMgr;
}

namespace ksys::frm {

class BaseProcJob final : public sead::Job {
public:
    BaseProcJob() = default;
    void invoke() override;

    void set(BaseProcJobLink* link, int num_procs) {
        mJobLink = link;
        mNumProcs = num_procs;
    }

private:
    friend class BaseProcJobQue;

    BaseProcJobLink* mJobLink = nullptr;
    int mNumProcs = 0;
};

class BaseProcJobQue {
public:
    BaseProcJobQue();
    BaseProcJobQue(const BaseProcJobQue&) = delete;
    auto operator=(const BaseProcJobQue&) = delete;
    virtual ~BaseProcJobQue();

    void init(sead::Heap* heap);
    bool pushJobQueue(sead::WorkerMgr* worker_mgr, BaseProcJobLists* lists, int priority,
                      JobType type);
    bool enqueueJobs(sead::FixedSizeJQ* queue, BaseProcJobLists* lists, int priority, JobType type);
    bool enqueueJobRequests(sead::FixedSizeJQ* queue,
                            const agl::utl::AtomicPtrArray<BaseProcJobLink>& links);

    void clear() { mNumEnqueuedJobs = 0; }

private:
    bool pushJobs(sead::FixedSizeJQ* queue, BaseProcJobLists* lists, int priority,
                  bool should_reset_job_idx, JobType type);
    bool isIndexValid(int idx) const { return u32(idx) < u32(mPool.size()); }

    int mFreeJobIdx = 0;
    sead::FixedSizeJQ mJobQueue;
    sead::SafeArray<BaseProcJob, 1200> mPool;
    sead::Atomic<int> mNumEnqueuedJobs = 0;
};
KSYS_CHECK_SIZE_NX150(BaseProcJobQue, 0xbc38);

}  // namespace ksys::frm
