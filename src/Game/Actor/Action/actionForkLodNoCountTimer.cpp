#include "Game/Actor/Action/actionForkLodNoCountTimer.h"

namespace uking::action {

ForkLodNoCountTimer::ForkLodNoCountTimer(const InitArg& arg) : ForkSetEndState(arg) {}

ForkLodNoCountTimer::~ForkLodNoCountTimer() = default;

bool ForkLodNoCountTimer::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkLodNoCountTimer::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkLodNoCountTimer::leave_() {
    ForkSetEndState::leave_();
}

void ForkLodNoCountTimer::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mWaitFrame_s, "WaitFrame");
    getStaticParam(&mWaitFrameRand_s, "WaitFrameRand");
    getStaticParam(&mCamDist_s, "CamDist");
    getStaticParam(&mIsTrgStart_s, "IsTrgStart");
}

void ForkLodNoCountTimer::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
