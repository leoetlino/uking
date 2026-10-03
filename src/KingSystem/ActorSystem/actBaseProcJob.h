#pragma once

#include <container/seadSafeArray.h>
#include <container/seadTList.h>
#include <mc/seadJob.h>
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class BaseProc;

enum class CalcPrio {
    PlayerBefore = 0,
    Player = 1,
    PlayerAfter = 2,
    AllAfter = 3,
};

enum class JobType {
    PreCalc = 0,
    PostBg = 1,
    PostSensor = 2,
    Signal = 3,
    FrameEnd = 4,
    AfterMessageDispatch = 5,
    AfterSignal = 6,
    Invalid = 7,
};

class BaseProcJobLink : public sead::TListNode<BaseProc*> {
public:
    BaseProcJobLink(BaseProc* proc, u8 priority);

    BaseProc* getProc() const { return mData; }

    u8 getPriority() const { return mPriority; }
    u8 getSubPriority() const { return mSubPriority; }

    void setNewPriority(u8 priority) { mNewPriority = priority; }
    void setNewSubPriority(u8 priority) { mNewSubPriority = priority; }

    void loadNewPriority() { mPriority = mNewPriority; }
    void loadNewSubPriority() { mSubPriority = mNewSubPriority; }

    bool hasPriorityChange() const {
        return mPriority != mNewPriority || mSubPriority != mNewSubPriority;
    }

private:
    u8 mPriority;
    u8 mNewPriority;
    u8 mSubPriority;
    u8 mNewSubPriority;
};
KSYS_CHECK_SIZE_NX150(BaseProcJobLink, 0x28);

struct BaseProcJobList {
    sead::TListNode<BaseProc*>* front() const;
    sead::TListNode<BaseProc*>* next(BaseProcJobLink* link) const;
    int size() const;

    sead::SafeArray<sead::TList<BaseProc*>, 2> sub_lists;
};

class BaseProcJobLists {
public:
    BaseProcJobLists() = default;
    ~BaseProcJobLists() { ; }

    void pushJob(BaseProcJobLink& link);
    void eraseJob(BaseProcJobLink& link);
    sead::TListNode<BaseProc*>* getJobWithTopPriority() const;
    sead::TListNode<BaseProc*>* getNextJobWithTopPriority(BaseProcJobLink* link) const;
    sead::TListNode<BaseProc*>* getNextJob(BaseProcJobLink* link) const;
    BaseProcJobList& getList(int idx) { return mLists[idx]; }
    const BaseProcJobList& getList(int idx) const { return mLists[idx]; }

private:
    sead::SafeArray<BaseProcJobList, 8> mLists{};
};

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

}  // namespace ksys::act
