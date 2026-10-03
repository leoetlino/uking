#include "KingSystem/ActorSystem/actBaseProcJob.h"
#include "KingSystem/ActorSystem/actBaseProcMgr.h"
#include "KingSystem/Utils/InitTimeInfo.h"

namespace ksys::act {

static util::InitTimeInfo sInfo;

BaseProcJobLink::BaseProcJobLink(BaseProc* proc, u8 priority)
    : TListNode(proc), mPriority(priority), mNewPriority(priority), mSubPriority(3),
      mNewSubPriority(3) {}

sead::TListNode<BaseProc*>* BaseProcJobList::front() const {
    for (const auto& list : sub_lists) {
        if (list.front())
            return list.front();
    }
    return nullptr;
}

sead::TListNode<BaseProc*>* BaseProcJobList::next(BaseProcJobLink* link) const {
    if (auto* next = sub_lists[link->getSubPriority() >> 1].next(link))
        return next;

    for (int i = (link->getSubPriority() >> 1) + 1; i < sub_lists.size(); ++i) {
        if (sub_lists[i].front())
            return sub_lists[i].front();
    }

    return nullptr;
}

int BaseProcJobList::size() const {
    return sub_lists[0].size() + sub_lists[1].size();
}

void BaseProcJobLists::pushJob(BaseProcJobLink& link) {
    if (link.isLinked())
        return;

    auto& list = mLists[link.getPriority()].sub_lists[link.getSubPriority() >> 1];
    if (link.getSubPriority() % 2 == 0)
        list.pushFront(&link);
    else
        list.pushBack(&link);
}

void BaseProcJobLists::eraseJob(BaseProcJobLink& link) {
    if (link.isLinked())
        link.erase();
}

sead::TListNode<BaseProc*>* BaseProcJobLists::getJobWithTopPriority() const {
    for (const auto& list : mLists) {
        if (auto* result = list.front())
            return result;
    }
    return nullptr;
}

sead::TListNode<BaseProc*>*
BaseProcJobLists::getNextJobWithTopPriority(BaseProcJobLink* link) const {
    if (auto* next = getNextJob(link))
        return next;

    for (u32 i = link->getPriority() + 1; i < u32(mLists.size()); ++i) {
        if (auto* next = mLists[i].front())
            return next;
    }

    return nullptr;
}

sead::TListNode<BaseProc*>* BaseProcJobLists::getNextJob(BaseProcJobLink* link) const {
    return mLists[link->getPriority()].next(link);
}

void BaseProcJob::invoke() {
    BaseProcMgr::instance()->jobInvoked(mJobLink, mNumProcs);
}

}  // namespace ksys::act
