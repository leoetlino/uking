#include "Game/Actor/Player/Action/actionForkOnEnterDropWeaponWithSpeed.h"

namespace uking::action {

ForkOnEnterDropWeaponWithSpeed::ForkOnEnterDropWeaponWithSpeed(const InitArg& arg)
    : ForkDropWeaponWithSpeedBase(arg) {}

ForkOnEnterDropWeaponWithSpeed::~ForkOnEnterDropWeaponWithSpeed() = default;

bool ForkOnEnterDropWeaponWithSpeed::init_(sead::Heap* heap) {
    return ForkDropWeaponWithSpeedBase::init_(heap);
}

void ForkOnEnterDropWeaponWithSpeed::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkDropWeaponWithSpeedBase::enter_(params);
}

void ForkOnEnterDropWeaponWithSpeed::leave_() {
    ForkDropWeaponWithSpeedBase::leave_();
}

void ForkOnEnterDropWeaponWithSpeed::loadParams_() {
    ForkDropWeaponWithSpeedBase::loadParams_();
}

void ForkOnEnterDropWeaponWithSpeed::calc_() {
    ForkDropWeaponWithSpeedBase::calc_();
}

}  // namespace uking::action
