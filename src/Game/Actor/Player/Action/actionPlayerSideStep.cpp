#include "Game/Actor/Player/Action/actionPlayerSideStep.h"

namespace uking::action {

PlayerSideStep::PlayerSideStep(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSideStep::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSideStep::leave_() {
    PlayerBase::leave_();
}

void PlayerSideStep::loadParams_() {
    getStaticParam(&mSpeedF_s, "SpeedF");
    getStaticParam(&mHeight_s, "Height");
    getStaticParam(&mFSpeedF_s, "FSpeedF");
    getStaticParam(&mFHeight_s, "FHeight");
    getStaticParam(&mUHeight_s, "UHeight");
    getStaticParam(&mNoDamageTime_s, "NoDamageTime");
    getStaticParam(&mJustAvoidTime_s, "JustAvoidTime");
    getStaticParam(&mForceSlowTime_s, "ForceSlowTime");
    getStaticParam(&mMySlowStartFrame_s, "MySlowStartFrame");
}

void PlayerSideStep::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
