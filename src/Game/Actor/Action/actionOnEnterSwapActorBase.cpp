#include "Game/Actor/Action/actionOnEnterSwapActorBase.h"

namespace uking::action {

OnEnterSwapActorBase::OnEnterSwapActorBase(const InitArg& arg) : ForkSetEndState(arg) {}

OnEnterSwapActorBase::~OnEnterSwapActorBase() = default;

bool OnEnterSwapActorBase::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void OnEnterSwapActorBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void OnEnterSwapActorBase::leave_() {
    ForkSetEndState::leave_();
}

void OnEnterSwapActorBase::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mOnGroundPos_s, "OnGroundPos");
}

void OnEnterSwapActorBase::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
