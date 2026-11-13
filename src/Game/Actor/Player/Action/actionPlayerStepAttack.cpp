#include "Game/Actor/Player/Action/actionPlayerStepAttack.h"

namespace uking::action {

PlayerStepAttack::PlayerStepAttack(const InitArg& arg) : PlayerBase(arg) {}

void PlayerStepAttack::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerStepAttack::leave_() {
    PlayerBase::leave_();
}

void PlayerStepAttack::loadParams_() {
    getStaticParam(&mJumpHeight_s, "JumpHeight");
}

void PlayerStepAttack::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
