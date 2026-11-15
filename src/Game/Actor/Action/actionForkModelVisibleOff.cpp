#include "Game/Actor/Action/actionForkModelVisibleOff.h"

namespace uking::action {

ForkModelVisibleOff::ForkModelVisibleOff(const InitArg& arg) : ForkSetEndState(arg) {}

ForkModelVisibleOff::~ForkModelVisibleOff() = default;

bool ForkModelVisibleOff::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkModelVisibleOff::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkModelVisibleOff::leave_() {
    ForkSetEndState::leave_();
}

void ForkModelVisibleOff::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mUseFadeIn_s, "UseFadeIn");
    getStaticParam(&mUseASEvent_s, "UseASEvent");
}

void ForkModelVisibleOff::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
