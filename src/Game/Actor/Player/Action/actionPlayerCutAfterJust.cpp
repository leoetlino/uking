#include "Game/Actor/Player/Action/actionPlayerCutAfterJust.h"

namespace uking::action {

PlayerCutAfterJust::PlayerCutAfterJust(const InitArg& arg) : PlayerBase(arg) {}

void PlayerCutAfterJust::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCutAfterJust::leave_() {
    PlayerBase::leave_();
}

void PlayerCutAfterJust::loadParams_() {
    getStaticParam(&mSlowContTime_s, "SlowContTime");
    getStaticParam(&mLastCutAcceptTime_s, "LastCutAcceptTime");
    getStaticParam(&mLastCutAcceptTimeLSword_s, "LastCutAcceptTimeLSword");
    getStaticParam(&mLastCutAcceptTimeSpear_s, "LastCutAcceptTimeSpear");
    getStaticParam(&mForceSlowTime_s, "ForceSlowTime");
}

void PlayerCutAfterJust::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
