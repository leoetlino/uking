#include "Game/Actor/Player/Action/actionPlayerWaterDivingJump.h"

namespace uking::action {

PlayerWaterDivingJump::PlayerWaterDivingJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWaterDivingJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWaterDivingJump::leave_() {
    PlayerBase::leave_();
}

void PlayerWaterDivingJump::loadParams_() {
    getStaticParam(&mDiveSpeedF_s, "DiveSpeedF");
    getStaticParam(&mDiveHeight_s, "DiveHeight");
    getStaticParam(&mDiveSpeedDec_s, "DiveSpeedDec");
}

void PlayerWaterDivingJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
