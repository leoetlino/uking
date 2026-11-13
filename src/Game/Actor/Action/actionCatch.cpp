#include "Game/Actor/Action/actionCatch.h"

namespace uking::action {

Catch::Catch(const InitArg& arg) : act::ActionEx(arg) {}

Catch::~Catch() = default;

void Catch::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void Catch::leave_() {
    act::ActionEx::leave_();
}

void Catch::loadParams_() {
    getStaticParam(&mWeaponIdx_s, "WeaponIdx");
    getDynamicParam(&mTargetWeapon_d, "TargetWeapon");
    getStaticParam(&mRotSpd_s, "RotSpd");
    getStaticParam(&mASName_s, "ASName");
}

void Catch::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
