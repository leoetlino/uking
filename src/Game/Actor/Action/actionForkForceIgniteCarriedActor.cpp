#include "Game/Actor/Action/actionForkForceIgniteCarriedActor.h"

namespace uking::action {

ForkForceIgniteCarriedActor::ForkForceIgniteCarriedActor(const InitArg& arg)
    : ForkSetEndState(arg) {}

ForkForceIgniteCarriedActor::~ForkForceIgniteCarriedActor() = default;

bool ForkForceIgniteCarriedActor::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkForceIgniteCarriedActor::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkForceIgniteCarriedActor::leave_() {
    ForkSetEndState::leave_();
}

void ForkForceIgniteCarriedActor::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mIsCheckAfterChildState_s, "IsCheckAfterChildState");
}

void ForkForceIgniteCarriedActor::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
