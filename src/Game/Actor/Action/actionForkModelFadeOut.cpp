#include "Game/Actor/Action/actionForkModelFadeOut.h"

namespace uking::action {

ForkModelFadeOut::ForkModelFadeOut(const InitArg& arg) : ForkSetEndState(arg) {}

ForkModelFadeOut::~ForkModelFadeOut() = default;

bool ForkModelFadeOut::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkModelFadeOut::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkModelFadeOut::leave_() {
    ForkSetEndState::leave_();
}

void ForkModelFadeOut::loadParams_() {
    ForkSetEndState::loadParams_();
}

void ForkModelFadeOut::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
