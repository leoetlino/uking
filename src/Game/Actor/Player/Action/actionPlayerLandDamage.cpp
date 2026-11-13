#include "Game/Actor/Player/Action/actionPlayerLandDamage.h"

namespace uking::action {

PlayerLandDamage::PlayerLandDamage(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLandDamage::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLandDamage::leave_() {
    PlayerBase::leave_();
}

void PlayerLandDamage::loadParams_() {
    getStaticParam(&mWaitTimeMin_s, "WaitTimeMin");
    getStaticParam(&mWaitTimeMax_s, "WaitTimeMax");
    getStaticParam(&mDeadHeight_s, "DeadHeight");
    getStaticParam(&mDamageMin_s, "DamageMin");
}

void PlayerLandDamage::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
