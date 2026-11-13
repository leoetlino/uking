#include "Game/Actor/Player/Action/actionPlayerWeaponThrow.h"

namespace uking::action {

PlayerWeaponThrow::PlayerWeaponThrow(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWeaponThrow::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWeaponThrow::leave_() {
    PlayerBase::leave_();
}

void PlayerWeaponThrow::loadParams_() {
    getStaticParam(&mThrowSpeedY_s, "ThrowSpeedY");
    getStaticParam(&mThrowSpeedF_s, "ThrowSpeedF");
    getStaticParam(&mSquatThrowSpeedF_s, "SquatThrowSpeedF");
}

void PlayerWeaponThrow::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
