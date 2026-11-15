#include "Game/Actor/Action/actionForkHopInAir.h"

namespace uking::action {

ForkHopInAir::ForkHopInAir(const InitArg& arg) : ForkSetEndState(arg) {}

ForkHopInAir::~ForkHopInAir() = default;

bool ForkHopInAir::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkHopInAir::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkHopInAir::leave_() {
    ForkSetEndState::leave_();
}

void ForkHopInAir::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mHopHeight_s, "HopHeight");
}

void ForkHopInAir::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
