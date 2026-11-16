#include "KingSystem/Resource/resMemoryMgr.h"
#include <heap/seadExpHeap.h>
#include "KingSystem/Resource/resResourceMgrTask.h"
#include "KingSystem/Resource/resResourceUnit.h"
#include "KingSystem/Resource/resSystem.h"
#include "KingSystem/Utils/HeapUtil.h"

namespace ksys::res {

MemoryMgr::MemoryMgr() {
    mUnits.initOffset(ResourceUnit::getArenaUnitListNodeOffset());
    mUnits2.initOffset(ResourceUnit::getArenaUnitListNode2Offset());
}

MemoryMgr::~MemoryMgr() {
    destroy();
}

// NON_MATCHING: branching at the end (csel instead of a branch)
bool MemoryMgr::init(const MemoryMgr::InitArg& arg) {
    if (!arg.heap) {
        stubbedLogFunction();
        return false;
    }

    if (arg.size == 0)
        stubbedLogFunction();

    mFlags.change(Flag::_1, arg.set_flag_1);

    mHeap = sead::ExpHeap::create(arg.size, arg.name, arg.heap, arg.alignment,
                                  sead::Heap::cHeapDirection_Forward, true);

    if (arg.use_best_fit_alloc_mode)
        mHeap->setAllocMode(sead::ExpHeap::AllocMode::BestFit);

    mHeapSize = mHeap->getSize();
    _cc = 0;
    mHeapFreeSize = mHeap->getFreeSize();
    mHeapName = mHeap->getName();
    mUsagePercentage = 0.0;
    _c8 = 0;
    mMinFreePercentage = arg.min_free_percentage;

    if (ResourceMgrTask::instance())
        ResourceMgrTask::instance()->insertMemoryMgr(this);

    mFlags.change(Flag::_20, arg.set_flag_20);
    mFlags.change(Flag::_10, arg.set_flag_10);

    struct UnusedTemp {
        sead::SafeString str;
        void* _10 = nullptr;
    };
    [[maybe_unused]] UnusedTemp temp;
    temp.str = arg.name;

    mFlags.change(Flag::_8, arg.set_flag_8);

    return true;
}

void MemoryMgr::stubbed() {}

void MemoryMgr::updateFlag8(bool on) {
    if (on != mFlags.isOn(Flag::_8) && mHeap)
        mFlags.change(Flag::_8, on);
}

void MemoryMgr::clearUnits() {
    if (!mHeap)
        return;

    stubbedLogFunction();
    auto lock = sead::makeScopedLock(mCS);
    for (auto& unit_ref : mUnits.robustRange()) {
        ResourceUnit* unit = &unit_ref;
        stubbedLogFunction();
        ResourceMgrTask::instance()->deregisterUnit(unit);
        ResourceMgrTask::instance()->requestClearCacheForSync(&unit, true, false);
    }
    stubbedLogFunction();
}

bool MemoryMgr::isFlag1Set() const {
    return mFlags.isOn(Flag::_1);
}

bool MemoryMgr::hasNoUnits() const {
    return mUnits.isEmpty();
}

s32 MemoryMgr::getNumUnits() const {
    return mUnits.size();
}

bool MemoryMgr::isFlag10Set() const {
    return mFlags.isOn(Flag::_10);
}

bool MemoryMgr::isFlag8Set() const {
    return mFlags.isOn(Flag::_8);
}

bool MemoryMgr::checkIsOom() const {
    if (!mHeap)
        return false;

    const f32 used_size = mUsage1 + mUsage2;
    const size_t heap_size = mHeap->getSize();
    const f32 free_percentage =
        100.0f *
        std::max<f32>(1.0 - used_size / (heap_size - sead::ExpHeap::getManagementAreaSize(8)), 0);

    if (free_percentage < mMinFreePercentage) {
        if (returnFalse())
            stubbedLogFunction();

        setBloodyMoonReasonForOom_();
        return true;
    }

    return false;
}

// FIXME: figure out what sead function this is
bool seadCheckPointer(void* ptr);

// NON_MATCHING: branching
util::DualHeap* MemoryMgr::makeDualHeap(u32 size, const sead::SafeString& name,
                                        sead::Heap::HeapDirection direction, ResourceUnit* unit,
                                        bool) {
    if (!mHeap)
        return nullptr;

    const auto alignment = getDefaultAlignment();
    const auto lock = sead::makeScopedLock(mCS);

    auto* heap = util::DualHeap::tryCreate(size, name, mHeap, mHeap2, alignment, direction, false);
    if (!heap) {
        if (returnFalse())
            stubbedLogFunction();

        if (!clearCachedResources(size))
            return nullptr;

        heap = util::DualHeap::tryCreate(size, name, mHeap, mHeap2, alignment, direction, false);
        if (!heap)
            return nullptr;
    }

    if (unit && !seadCheckPointer(unit)) {
        mUnits.pushBack(unit);
        mFlags.set(Flag::_2);
    }

    mFlags.set(Flag::_4);
    return heap;
}

void MemoryMgr::addSize(s32 size) {
    mSize += size;
}

void MemoryMgr::addSize2(s32 size) {
    mUsage1 += size;
}

}  // namespace ksys::res
