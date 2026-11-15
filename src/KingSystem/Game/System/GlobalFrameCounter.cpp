#include "KingSystem/Game/System/GlobalFrameCounter.h"

#include "KingSystem/System/VFR.h"

namespace ksys::game {

SEAD_SINGLETON_DISPOSER_IMPL(GlobalFrameCounter)

GlobalFrameCounter::~GlobalFrameCounter() = default;

void GlobalFrameCounter::init() {
    mVfrTimer = 0;
    mFrameCounterB = 0;
    mVfrTimer2 = 0;
    mFrameCounterB2 = 0;
    mFrameCounter = 0;
    mFrameCounter2 = 0;
}

void GlobalFrameCounter::init2() {
    init();
}

void GlobalFrameCounter::prepareStageUnload() {}

void GlobalFrameCounter::incrementCountersAndUpdate() {
    mFrameCounter++;
    mFrameCounter2++;
    f32 deltaTime = VFR::instance()->getDeltaFrame();
    mVfrTimer += deltaTime;

    while (mVfrTimer >= 1) {
        mFrameCounterB++;
        mVfrTimer--;
    }

    mVfrTimer2 += deltaTime;
    while (mVfrTimer2 >= 1) {
        mFrameCounterB2++;
        mVfrTimer2--;
    }
}

void GlobalFrameCounter::incrementCounters() {
    mFrameCounter++;
    mFrameCounterB++;
}

}  // namespace ksys::game
