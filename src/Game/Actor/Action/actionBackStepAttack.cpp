#include "Game/Actor/Action/actionBackStepAttack.h"

namespace uking::action {

BackStepAttack::BackStepAttack(const InitArg& arg) : BackStepFromTarget(arg) {}

BackStepAttack::~BackStepAttack() = default;

void BackStepAttack::enter_(ksys::act::ai::InlineParamPack* params) {
    BackStepFromTarget::enter_(params);
}

void BackStepAttack::leave_() {
    BackStepFromTarget::leave_();
}

void BackStepAttack::loadParams_() {
    BackStepFromTarget::loadParams_();
    getStaticParam(&mWeaponIdx_s, "WeaponIdx");
    getStaticParam(&mMoveDist_s, "MoveDist");
    getStaticParam(&mJustAvoidSideDist_s, "JustAvoidSideDist");
    getStaticParam(&mJustAvoidBackDist_s, "JustAvoidBackDist");
    getStaticParam(&mJustAvoidAngle_s, "JustAvoidAngle");
}

void BackStepAttack::calc_() {
    BackStepFromTarget::calc_();
}

}  // namespace uking::action
