#include "Game/Actor/Player/Action/actionPlayerStepGuardJust.h"

namespace uking::action {

PlayerStepGuardJust::PlayerStepGuardJust(const InitArg& arg) : PlayerBase(arg) {}

void PlayerStepGuardJust::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerStepGuardJust::leave_() {
    PlayerBase::leave_();
}

void PlayerStepGuardJust::loadParams_() {
    getStaticParam(&mJumpHeight_s, "JumpHeight");
}

void PlayerStepGuardJust::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
