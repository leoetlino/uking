#include "Game/Actor/Player/Action/actionPlayerSwimSpinAttack.h"

namespace uking::action {

PlayerSwimSpinAttack::PlayerSwimSpinAttack(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSwimSpinAttack::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSwimSpinAttack::leave_() {
    PlayerBase::leave_();
}

void PlayerSwimSpinAttack::loadParams_() {
    getStaticParam(&mEnergyDash_s, "EnergyDash");
}

void PlayerSwimSpinAttack::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
