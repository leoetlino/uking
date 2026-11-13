#include "Game/Actor/Player/Action/actionPlayerWallJump.h"

namespace uking::action {

PlayerWallJump::PlayerWallJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWallJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWallJump::leave_() {
    PlayerBase::leave_();
}

void PlayerWallJump::loadParams_() {
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mJumpSpeedF_s, "JumpSpeedF");
}

void PlayerWallJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
