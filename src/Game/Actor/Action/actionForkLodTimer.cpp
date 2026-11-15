#include "Game/Actor/Action/actionForkLodTimer.h"

namespace uking::action {

ForkLodTimer::ForkLodTimer(const InitArg& arg) : ForkSetEndState(arg) {}

ForkLodTimer::~ForkLodTimer() = default;

bool ForkLodTimer::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkLodTimer::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkLodTimer::leave_() {
    ForkSetEndState::leave_();
}

void ForkLodTimer::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mWaitFrame_s, "WaitFrame");
}

void ForkLodTimer::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
