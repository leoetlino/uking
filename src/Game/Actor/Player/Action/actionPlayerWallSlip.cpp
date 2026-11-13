#include "Game/Actor/Player/Action/actionPlayerWallSlip.h"

namespace uking::action {

PlayerWallSlip::PlayerWallSlip(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWallSlip::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWallSlip::leave_() {
    PlayerBase::leave_();
}

void PlayerWallSlip::loadParams_() {
    getStaticParam(&mJumpHeight_s, "JumpHeight");
}

void PlayerWallSlip::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
