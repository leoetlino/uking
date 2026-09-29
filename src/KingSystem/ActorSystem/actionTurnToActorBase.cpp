#include "KingSystem/ActorSystem/actionTurnToActorBase.h"

namespace ksys::act::ai {

TurnToActorBase::TurnToActorBase(const InitArg& arg) : Action(arg) {}

TurnToActorBase::~TurnToActorBase() = default;

bool TurnToActorBase::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void TurnToActorBase::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void TurnToActorBase::leave_() {
    Action::leave_();
}

void TurnToActorBase::loadParams_() {}

void TurnToActorBase::calc_() {
    Action::calc_();
}

}  // namespace ksys::act::ai
