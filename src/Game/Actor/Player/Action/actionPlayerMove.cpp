#include "Game/Actor/Player/Action/actionPlayerMove.h"

namespace uking::action {

PlayerMove::PlayerMove(const InitArg& arg) : PlayerBase(arg) {}

void PlayerMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerMove::leave_() {
    PlayerBase::leave_();
}

void PlayerMove::loadParams_() {
    getStaticParam(&mEnergyDash_s, "EnergyDash");
    getStaticParam(&mForceApplyPushAnm_s, "ForceApplyPushAnm");
    getStaticParam(&mEnergyDashTrig_s, "EnergyDashTrig");
    getStaticParam(&mPushContinueTime_s, "PushContinueTime");
    getStaticParam(&mPushStopDistY_s, "PushStopDistY");
    getStaticParam(&mInvalidFallFrame_s, "InvalidFallFrame");
}

void PlayerMove::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
