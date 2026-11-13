#include "Game/Actor/Action/actionForkDropWeaponWithSpeed.h"

namespace uking::action {

ForkDropWeaponWithSpeed::ForkDropWeaponWithSpeed(const InitArg& arg)
    : ForkDropWeaponWithSpeedBase(arg) {}

ForkDropWeaponWithSpeed::~ForkDropWeaponWithSpeed() = default;

void ForkDropWeaponWithSpeed::calc_() {
    ForkDropWeaponWithSpeedBase::calc_();
}

}  // namespace uking::action
