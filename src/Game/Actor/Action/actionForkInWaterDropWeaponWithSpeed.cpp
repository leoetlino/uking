#include "Game/Actor/Action/actionForkInWaterDropWeaponWithSpeed.h"

namespace uking::action {

ForkInWaterDropWeaponWithSpeed::ForkInWaterDropWeaponWithSpeed(const InitArg& arg)
    : ForkDropWeaponWithSpeedBase(arg) {}

ForkInWaterDropWeaponWithSpeed::~ForkInWaterDropWeaponWithSpeed() = default;

bool ForkInWaterDropWeaponWithSpeed::init_(sead::Heap* heap) {
    return ForkDropWeaponWithSpeedBase::init_(heap);
}

void ForkInWaterDropWeaponWithSpeed::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkDropWeaponWithSpeedBase::enter_(params);
}

void ForkInWaterDropWeaponWithSpeed::leave_() {
    ForkDropWeaponWithSpeedBase::leave_();
}

void ForkInWaterDropWeaponWithSpeed::loadParams_() {
    ForkDropWeaponWithSpeedBase::loadParams_();
    getStaticParam(&mInWaterDepth_s, "InWaterDepth");
    getStaticParam(&mOutWaterDepth_s, "OutWaterDepth");
}

void ForkInWaterDropWeaponWithSpeed::calc_() {
    ForkDropWeaponWithSpeedBase::calc_();
}

}  // namespace uking::action
