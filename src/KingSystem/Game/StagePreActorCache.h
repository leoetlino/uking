#pragma once

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

namespace ksys::gfx {
class ForestRenderer;
}

namespace ksys::act {
class LazyTraverseList;
}

namespace ksys::game {

// TODO
class StagePreActorCache {
    SEAD_SINGLETON_DISPOSER(StagePreActorCache)
    StagePreActorCache();

public:
    act::LazyTraverseList* getObjects() const { return mObjects; }
    auto* getForestRenderer() { return mForestRenderer; }

private:
    char _0[0x20];
    act::LazyTraverseList* mObjects;
    gfx::ForestRenderer* mForestRenderer;
};

}  // namespace ksys::game
