#include "KingSystem/Game/Area/Action/actionAreaActorObserve.h"

namespace ksys::game {

AreaActorObserve::AreaActorObserve(const InitArg& arg) : AreaActionBase(arg) {}

AreaActorObserve::~AreaActorObserve() = default;

bool AreaActorObserve::init_(sead::Heap* heap) {
    return AreaActionBase::init_(heap);
}

void AreaActorObserve::loadParams_() {
    getMapUnitParam(&mCount_m, "Count");
    getMapUnitParam(&mIsSendMessage_m, "IsSendMessage");
    getMapUnitParam(&mDefaultBasicSignal_m, "DefaultBasicSignal");
}

}  // namespace ksys::game
