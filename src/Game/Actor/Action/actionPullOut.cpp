#include "Game/Actor/Action/actionPullOut.h"

namespace uking::action {

PullOut::PullOut(const InitArg& arg) : OnetimeStopBase(arg) {}

PullOut::~PullOut() = default;

bool PullOut::init_(sead::Heap* heap) {
    return OnetimeStopBase::init_(heap);
}

void PullOut::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void PullOut::leave_() {
    OnetimeStopBase::leave_();
}

void PullOut::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mAnimGrabPos_s, "AnimGrabPos");
    getDynamicParam(&mTargetActor_d, "TargetActor");
}

void PullOut::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
