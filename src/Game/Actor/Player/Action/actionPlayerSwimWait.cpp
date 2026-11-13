#include "Game/Actor/Player/Action/actionPlayerSwimWait.h"

namespace uking::action {

PlayerSwimWait::PlayerSwimWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSwimWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSwimWait::leave_() {
    PlayerBase::leave_();
}

void PlayerSwimWait::loadParams_() {
    getStaticParam(&mEnergyWait_s, "EnergyWait");
    getStaticParam(&mDecSpeedRate_s, "DecSpeedRate");
}

void PlayerSwimWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
