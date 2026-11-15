#include "Game/Actor/Action/actionForkEndByConditionBase.h"

namespace uking::action {

ForkEndByConditionBase::ForkEndByConditionBase(const InitArg& arg) : ForkSetEndState(arg) {}

ForkEndByConditionBase::~ForkEndByConditionBase() = default;

bool ForkEndByConditionBase::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkEndByConditionBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkEndByConditionBase::leave_() {
    ForkSetEndState::leave_();
}

void ForkEndByConditionBase::loadParams_() {
    ForkSetEndState::loadParams_();
}

void ForkEndByConditionBase::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
