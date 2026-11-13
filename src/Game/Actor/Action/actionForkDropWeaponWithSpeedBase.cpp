#include "Game/Actor/Action/actionForkDropWeaponWithSpeedBase.h"

namespace uking::action {

ForkDropWeaponWithSpeedBase::ForkDropWeaponWithSpeedBase(const InitArg& arg)
    : ksys::act::ai::Action(arg) {}

ForkDropWeaponWithSpeedBase::~ForkDropWeaponWithSpeedBase() = default;

bool ForkDropWeaponWithSpeedBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void ForkDropWeaponWithSpeedBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void ForkDropWeaponWithSpeedBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void ForkDropWeaponWithSpeedBase::loadParams_() {
    getStaticParam(&mWeaponIdx_s, "WeaponIdx");
    getStaticParam(&mWeaponDropSpeedXZ_s, "WeaponDropSpeedXZ");
    getStaticParam(&mWeaponDropSpeedY_s, "WeaponDropSpeedY");
    getStaticParam(&mAngleOffsetY_s, "AngleOffsetY");
    getStaticParam(&mChemReset_s, "ChemReset");
}

void ForkDropWeaponWithSpeedBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
