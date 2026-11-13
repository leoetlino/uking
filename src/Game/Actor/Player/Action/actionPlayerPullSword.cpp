#include "Game/Actor/Player/Action/actionPlayerPullSword.h"

namespace uking::action {

PlayerPullSword::PlayerPullSword(const InitArg& arg) : PlayerBase(arg) {}

void PlayerPullSword::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerPullSword::leave_() {
    PlayerBase::leave_();
}

void PlayerPullSword::loadParams_() {
    getStaticParam(&mLifeDecInterval1_s, "LifeDecInterval1");
    getStaticParam(&mLifeDecInterval2_s, "LifeDecInterval2");
    getStaticParam(&mLifeDecInterval3_s, "LifeDecInterval3");
    getStaticParam(&mLifeDecInterval4_s, "LifeDecInterval4");
    getStaticParam(&mLifeDecInterval5_s, "LifeDecInterval5");
    getStaticParam(&mInterruptInterval_s, "InterruptInterval");
    getStaticParam(&mSuccessLife_s, "SuccessLife");
}

void PlayerPullSword::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
