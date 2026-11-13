#include "Game/Actor/Player/Action/actionPlayerIce.h"

namespace uking::action {

PlayerIce::PlayerIce(const InitArg& arg) : PlayerBase(arg) {}

void PlayerIce::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerIce::leave_() {
    PlayerBase::leave_();
}

void PlayerIce::loadParams_() {
    getStaticParam(&mEnergyIce_s, "EnergyIce");
    getStaticParam(&mCountRate_s, "CountRate");
    getStaticParam(&mInputInterval_s, "InputInterval");
    getStaticParam(&mJumpSpeedF_s, "JumpSpeedF");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mJumpSpeedFBlowOff_s, "JumpSpeedFBlowOff");
    getStaticParam(&mJumpHeightBlowOff_s, "JumpHeightBlowOff");
}

void PlayerIce::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
