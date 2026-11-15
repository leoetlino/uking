#include "Game/Actor/Action/actionForkMoveDistanceCheckByDistance.h"

namespace uking::action {

ForkMoveDistanceCheckByDistance::ForkMoveDistanceCheckByDistance(const InitArg& arg)
    : ForkSetEndState(arg) {}

ForkMoveDistanceCheckByDistance::~ForkMoveDistanceCheckByDistance() = default;

bool ForkMoveDistanceCheckByDistance::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkMoveDistanceCheckByDistance::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkMoveDistanceCheckByDistance::leave_() {
    ForkSetEndState::leave_();
}

void ForkMoveDistanceCheckByDistance::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mIsCheckOnlyXZ_s, "IsCheckOnlyXZ");
}

void ForkMoveDistanceCheckByDistance::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
