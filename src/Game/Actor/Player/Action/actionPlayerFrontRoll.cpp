#include "Game/Actor/Player/Action/actionPlayerFrontRoll.h"

namespace uking::action {

PlayerFrontRoll::PlayerFrontRoll(const InitArg& arg) : PlayerBase(arg) {}

void PlayerFrontRoll::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerFrontRoll::leave_() {
    PlayerBase::leave_();
}

void PlayerFrontRoll::loadParams_() {
    getStaticParam(&mEnergyDec_s, "EnergyDec");
    getStaticParam(&mSpeedDecByAngle_s, "SpeedDecByAngle");
}

void PlayerFrontRoll::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
