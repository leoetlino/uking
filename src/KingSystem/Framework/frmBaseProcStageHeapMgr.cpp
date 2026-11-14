#include "KingSystem/Framework/frmBaseProcStageHeapMgr.h"

namespace ksys::frm {

SEAD_SINGLETON_DISPOSER_IMPL(BaseProcStageHeapMgr)

BaseProcStageHeapMgr::BaseProcStageHeapMgr() = default;

BaseProcStageHeapMgr::~BaseProcStageHeapMgr() = default;

sead::Heap* BaseProcStageHeapMgr::getHeap() const {
    return mHeap;
}

void BaseProcStageHeapMgr::setHeap(sead::Heap* heap) {
    mHeap = heap;
}

}  // namespace ksys::frm
