#include "Game/Actor/Player/Action/actionPlayerSwimMove.h"

namespace uking::action {

PlayerSwimMove::PlayerSwimMove(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSwimMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSwimMove::leave_() {
    PlayerBase::leave_();
}

void PlayerSwimMove::loadParams_() {
    getStaticParam(&mMaxSpeedF_s, "MaxSpeedF");
    getStaticParam(&mMaxSpeedS_s, "MaxSpeedS");
    getStaticParam(&mMaxSpeedB_s, "MaxSpeedB");
    getStaticParam(&mMaxSpeedDash_s, "MaxSpeedDash");
    getStaticParam(&mEnergyMove_s, "EnergyMove");
    getStaticParam(&mEnergyDash_s, "EnergyDash");
    getStaticParam(&mDecSpeedRate_s, "DecSpeedRate");
}

void PlayerSwimMove::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
