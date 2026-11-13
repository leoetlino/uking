#include "KingSystem/Framework/frmBaseProcAccessor.h"
#include "KingSystem/ActorSystem/actBaseProc.h"
#include "KingSystem/ActorSystem/actBaseProcMgr.h"
#include "KingSystem/Utils/Debug.h"

namespace ksys::frm {

BaseProcAccessor::~BaseProcAccessor() {
    if (mAcquired && mProc)
        mProc->release();

    mAcquired = false;
    mProc = nullptr;
}

bool BaseProcAccessor::acquire(act::BaseProc* proc) {
    if (mProc) {
        if (mAcquired)
            mProc->release();

        mAcquired = false;
        mProc = nullptr;
    }

    return proc && proc->acquire(*this);
}

bool acquireProc(BaseProcAccessor* accessor, act::BaseProc* proc, const sead::SafeString& from,
                 s32) {
    bool acquired = false;

    if (accessor) {
        acquired = accessor->acquire(proc);
        if (!acquired)
            return false;
    }

    if (acquired || act::BaseProcMgr::instance()->isHighPriorityThread())
        return true;

    sead::FixedSafeString<256> message;
    // (%s)Acquiring from a low priority thread. Please change via ActorLinkConstDataAccess
    message.format("(%s)低スレッドからの取得です。ActorLinkConstDataAccess経由に変更お願いします",
                   from.cstr());
    util::PrintDebug(message);
    return false;
}

}  // namespace ksys::frm
