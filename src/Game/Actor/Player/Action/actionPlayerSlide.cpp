#include "Game/Actor/Player/Action/actionPlayerSlide.h"

namespace uking::action {

PlayerSlide::PlayerSlide(const InitArg& arg) : PlayerBase(arg) {}

PlayerSlide::~PlayerSlide() = default;

void PlayerSlide::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSlide::leave_() {
    PlayerBase::leave_();
}

void PlayerSlide::loadParams_() {
    getStaticParam(&mUpKeyInvalidTime_s, "UpKeyInvalidTime");
    getStaticParam(&mFrontSlideMaxSpeedF_s, "FrontSlideMaxSpeedF");
    getStaticParam(&mBackSlideMaxSpeedF_s, "BackSlideMaxSpeedF");
    getStaticParam(&mLimitAngleDegStart_s, "LimitAngleDegStart");
    getStaticParam(&mMaxSlipSpeed_s, "MaxSlipSpeed");
    getStaticParam(&mSlipSpeedAdd_s, "SlipSpeedAdd");
    getStaticParam(&mSlipSpeedDec_s, "SlipSpeedDec");
    getStaticParam(&mEffectContTime_s, "EffectContTime");
}

void PlayerSlide::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
