#include "Game/Actor/Action/actionForkGanonBeastWeakPoint.h"

namespace uking::action {

ForkGanonBeastWeakPoint::ForkGanonBeastWeakPoint(const InitArg& arg) : ForkSetEndState(arg) {}

ForkGanonBeastWeakPoint::~ForkGanonBeastWeakPoint() = default;

bool ForkGanonBeastWeakPoint::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkGanonBeastWeakPoint::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkGanonBeastWeakPoint::leave_() {
    ForkSetEndState::leave_();
}

void ForkGanonBeastWeakPoint::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mTargetSlotIdx_s, "TargetSlotIdx");
    getAITreeVariable(&mIsWeakPointAppearMode_a, "IsWeakPointAppearMode");
    getAITreeVariable(&mWeakPointActiveFlag_a, "WeakPointActiveFlag");
    getAITreeVariable(&mWeakPointAliveFlag_a, "WeakPointAliveFlag");
}

void ForkGanonBeastWeakPoint::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
