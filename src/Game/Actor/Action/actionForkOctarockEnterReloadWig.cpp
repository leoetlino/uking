#include "Game/Actor/Action/actionForkOctarockEnterReloadWig.h"

namespace uking::action {

ForkOctarockEnterReloadWig::ForkOctarockEnterReloadWig(const InitArg& arg) : ForkSetEndState(arg) {}

ForkOctarockEnterReloadWig::~ForkOctarockEnterReloadWig() = default;

bool ForkOctarockEnterReloadWig::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkOctarockEnterReloadWig::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkOctarockEnterReloadWig::leave_() {
    ForkSetEndState::leave_();
}

void ForkOctarockEnterReloadWig::loadParams_() {
    ForkSetEndState::loadParams_();
    // FIXME: CALL _ZN4sead14SafeStringBaseIcEaSERKS1_ @ 0x7100b0caa0
    getAITreeVariable(&mOctarockFormChangeUnit_a, "OctarockFormChangeUnit");
}

void ForkOctarockEnterReloadWig::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
