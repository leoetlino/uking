#include "Game/Actor/Action/actionJumpToTargetBase.h"

namespace uking::action {

JumpToTargetBase::JumpToTargetBase(const InitArg& arg) : ksys::act::ai::Action(arg) {}

JumpToTargetBase::~JumpToTargetBase() = default;

bool JumpToTargetBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void JumpToTargetBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void JumpToTargetBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void JumpToTargetBase::loadParams_() {
    getStaticParam(&mMaxSpeed_s, "MaxSpeed");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mJumpGravity_s, "JumpGravity");
    getStaticParam(&mPosReduceRatioOnGround_s, "PosReduceRatioOnGround");
    getStaticParam(&mRotReduceRatioOnGround_s, "RotReduceRatioOnGround");
    getStaticParam(&mInWaterDepth_s, "InWaterDepth");
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

void JumpToTargetBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
