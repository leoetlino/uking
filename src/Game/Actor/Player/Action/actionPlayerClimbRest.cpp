#include "Game/Actor/Player/Action/actionPlayerClimbRest.h"

namespace uking::action {

PlayerClimbRest::PlayerClimbRest(const InitArg& arg) : PlayerBase(arg) {}

PlayerClimbRest::~PlayerClimbRest() = default;

void PlayerClimbRest::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerClimbRest::leave_() {
    PlayerBase::leave_();
}

void PlayerClimbRest::loadParams_() {
    getStaticParam(&mEnergyClimb_s, "EnergyClimb");
}

void PlayerClimbRest::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
