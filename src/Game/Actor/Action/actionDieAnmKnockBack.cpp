#include "Game/Actor/Action/actionDieAnmKnockBack.h"

namespace uking::action {

DieAnmKnockBack::DieAnmKnockBack(const InitArg& arg) : KnockBackNoRotBase(arg) {}

DieAnmKnockBack::~DieAnmKnockBack() = default;

void DieAnmKnockBack::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackNoRotBase::enter_(params);
}

void DieAnmKnockBack::leave_() {
    KnockBackNoRotBase::leave_();
}

void DieAnmKnockBack::loadParams_() {
    KnockBackHitImpactForce::loadParams_();
    getStaticParam(&mWeaponDropSpeedY_s, "WeaponDropSpeedY");
    getStaticParam(&mIsDropWeapon_s, "IsDropWeapon");
    getStaticParam(&mASName_s, "ASName");
}

void DieAnmKnockBack::calc_() {
    KnockBackNoRotBase::calc_();
}

}  // namespace uking::action
