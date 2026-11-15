#include "Game/Actor/Action/actionForkIgniteCarriedActor.h"

namespace uking::action {

ForkIgniteCarriedActor::ForkIgniteCarriedActor(const InitArg& arg) : ForkSetEndState(arg) {}

ForkIgniteCarriedActor::~ForkIgniteCarriedActor() = default;

bool ForkIgniteCarriedActor::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkIgniteCarriedActor::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkIgniteCarriedActor::leave_() {
    ForkSetEndState::leave_();
}

void ForkIgniteCarriedActor::loadParams_() {
    ForkSetEndState::loadParams_();
}

void ForkIgniteCarriedActor::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
