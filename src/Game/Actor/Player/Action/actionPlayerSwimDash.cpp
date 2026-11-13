#include "Game/Actor/Player/Action/actionPlayerSwimDash.h"

namespace uking::action {

PlayerSwimDash::PlayerSwimDash(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSwimDash::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSwimDash::leave_() {
    PlayerBase::leave_();
}

void PlayerSwimDash::loadParams_() {
    getStaticParam(&mEnergyDash_s, "EnergyDash");
}

void PlayerSwimDash::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
