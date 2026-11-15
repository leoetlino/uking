#include "Game/Actor/Action/actionForkEndByDistance.h"

namespace uking::action {

ForkEndByDistance::ForkEndByDistance(const InitArg& arg) : ForkSetEndState(arg) {}

ForkEndByDistance::~ForkEndByDistance() = default;

bool ForkEndByDistance::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkEndByDistance::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkEndByDistance::leave_() {
    ForkSetEndState::leave_();
}

void ForkEndByDistance::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mWeaponIdx_s, "WeaponIdx");
    getStaticParam(&mEndMode_s, "EndMode");
    getStaticParam(&mEndDist_s, "EndDist");
    getStaticParam(&mIsOnlyXZ_s, "IsOnlyXZ");
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

void ForkEndByDistance::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
