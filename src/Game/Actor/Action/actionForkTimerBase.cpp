#include "Game/Actor/Action/actionForkTimerBase.h"

namespace uking::action {

ForkTimerBase::ForkTimerBase(const InitArg& arg) : ForkSetEndState(arg) {}

ForkTimerBase::~ForkTimerBase() = default;

bool ForkTimerBase::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkTimerBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkTimerBase::leave_() {
    ForkSetEndState::leave_();
}

void ForkTimerBase::loadParams_() {
    ForkSetEndState::loadParams_();
}

void ForkTimerBase::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
