#include "Game/Actor/Action/actionForkAddCalcScaleMapUnit.h"

namespace uking::action {

ForkAddCalcScaleMapUnit::ForkAddCalcScaleMapUnit(const InitArg& arg) : ForkSetEndState(arg) {}

ForkAddCalcScaleMapUnit::~ForkAddCalcScaleMapUnit() = default;

bool ForkAddCalcScaleMapUnit::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkAddCalcScaleMapUnit::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkAddCalcScaleMapUnit::leave_() {
    ForkSetEndState::leave_();
}

void ForkAddCalcScaleMapUnit::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mStartRate_s, "StartRate");
    getStaticParam(&mAddRate_s, "AddRate");
    getStaticParam(&mMinAddScaleRate_s, "MinAddScaleRate");
    getMapUnitParam(&mScaleTime_m, "ScaleTime");
}

void ForkAddCalcScaleMapUnit::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
