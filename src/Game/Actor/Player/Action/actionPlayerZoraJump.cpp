#include "Game/Actor/Player/Action/actionPlayerZoraJump.h"

namespace uking::action {

PlayerZoraJump::PlayerZoraJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerZoraJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerZoraJump::leave_() {
    PlayerBase::leave_();
}

void PlayerZoraJump::loadParams_() {
    getStaticParam(&mJumpSpeedF_s, "JumpSpeedF");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

void PlayerZoraJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
