#include "KingSystem/Game/Area/Action/actionAreaObserveActorBase.h"

namespace ksys::game {

AreaObserveActorBase::AreaObserveActorBase(const InitArg& arg) : AreaActionBase(arg) {}

AreaObserveActorBase::~AreaObserveActorBase() = default;

bool AreaObserveActorBase::init_(sead::Heap* heap) {
    return AreaActionBase::init_(heap);
}

void AreaObserveActorBase::loadParams_() {
    getMapUnitParam(&mCount_m, "Count");
    getMapUnitParam(&mIsSendMessage_m, "IsSendMessage");
    getMapUnitParam(&mDefaultBasicSignal_m, "DefaultBasicSignal");
}

}  // namespace ksys::game
