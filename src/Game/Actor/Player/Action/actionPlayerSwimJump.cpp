#include "Game/Actor/Player/Action/actionPlayerSwimJump.h"

namespace uking::action {

PlayerSwimJump::PlayerSwimJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSwimJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSwimJump::leave_() {
    PlayerBase::leave_();
}

void PlayerSwimJump::loadParams_() {
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mJumpSpeedF_s, "JumpSpeedF");
    getStaticParam(&mEnergyJump_s, "EnergyJump");
}

void PlayerSwimJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
