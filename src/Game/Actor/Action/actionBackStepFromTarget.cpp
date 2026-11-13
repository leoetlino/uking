#include "Game/Actor/Action/actionBackStepFromTarget.h"

namespace uking::action {

BackStepFromTarget::BackStepFromTarget(const InitArg& arg) : BackStepBase(arg) {}

BackStepFromTarget::~BackStepFromTarget() = default;

bool BackStepFromTarget::init_(sead::Heap* heap) {
    return BackStepBase::init_(heap);
}

void BackStepFromTarget::enter_(ksys::act::ai::InlineParamPack* params) {
    BackStepBase::enter_(params);
}

void BackStepFromTarget::leave_() {
    BackStepBase::leave_();
}

void BackStepFromTarget::loadParams_() {
    BackStepBase::loadParams_();
    getStaticParam(&mJumpDist_s, "JumpDist");
}

void BackStepFromTarget::calc_() {
    BackStepBase::calc_();
}

}  // namespace uking::action
