#include "Game/Actor/Action/actionForkAITreeValWeakPointTimer.h"

namespace uking::action {

ForkAITreeValWeakPointTimer::ForkAITreeValWeakPointTimer(const InitArg& arg)
    : ForkSetEndState(arg) {}

ForkAITreeValWeakPointTimer::~ForkAITreeValWeakPointTimer() = default;

bool ForkAITreeValWeakPointTimer::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkAITreeValWeakPointTimer::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkAITreeValWeakPointTimer::leave_() {
    ForkSetEndState::leave_();
}

void ForkAITreeValWeakPointTimer::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mTimer_s, "Timer");
    getAITreeVariable(&mWeakPointCounter_a, "WeakPointCounter");
}

void ForkAITreeValWeakPointTimer::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
