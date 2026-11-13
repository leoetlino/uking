#include "Game/Actor/Action/actionJumpToTarget.h"

namespace uking::action {

JumpToTarget::JumpToTarget(const InitArg& arg) : JumpToTargetBase(arg) {}

JumpToTarget::~JumpToTarget() = default;

bool JumpToTarget::init_(sead::Heap* heap) {
    return JumpToTargetBase::init_(heap);
}

void JumpToTarget::enter_(ksys::act::ai::InlineParamPack* params) {
    JumpToTargetBase::enter_(params);
}

void JumpToTarget::leave_() {
    JumpToTargetBase::leave_();
}

void JumpToTarget::loadParams_() {
    JumpToTargetBase::loadParams_();
    getStaticParam(&mPreJumpAS_s, "PreJumpAS");
    getStaticParam(&mJumpAS_s, "JumpAS");
    getStaticParam(&mLandAS_s, "LandAS");
}

void JumpToTarget::calc_() {
    JumpToTargetBase::calc_();
}

}  // namespace uking::action
