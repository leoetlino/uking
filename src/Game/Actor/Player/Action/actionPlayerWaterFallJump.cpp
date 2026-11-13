#include "Game/Actor/Player/Action/actionPlayerWaterFallJump.h"

namespace uking::action {

PlayerWaterFallJump::PlayerWaterFallJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWaterFallJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWaterFallJump::leave_() {
    PlayerBase::leave_();
}

void PlayerWaterFallJump::loadParams_() {
    getStaticParam(&mJumpSpeedF_s, "JumpSpeedF");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mJumpHeightWaterRemain_s, "JumpHeightWaterRemain");
    getStaticParam(&mJumpHeightWithZora_s, "JumpHeightWithZora");
}

void PlayerWaterFallJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
