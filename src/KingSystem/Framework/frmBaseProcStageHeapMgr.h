#pragma once

#include <heap/seadDisposer.h>

namespace ksys::frm {

class BaseProcStageHeapMgr {
    SEAD_SINGLETON_DISPOSER(BaseProcStageHeapMgr)
    BaseProcStageHeapMgr();
    virtual ~BaseProcStageHeapMgr();

public:
    sead::Heap* getHeap() const;
    void setHeap(sead::Heap* heap);

private:
    sead::Heap* mHeap{};
    u32 _30{};
};

}  // namespace ksys::frm
