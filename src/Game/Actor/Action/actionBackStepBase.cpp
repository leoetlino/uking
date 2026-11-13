#include "Game/Actor/Action/actionBackStepBase.h"

namespace uking::action {

BackStepBase::BackStepBase(const InitArg& arg) : act::ActionEx(arg) {}

BackStepBase::~BackStepBase() = default;

void BackStepBase::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void BackStepBase::leave_() {
    act::ActionEx::leave_();
}

void BackStepBase::loadParams_() {
    getDynamicParam(&mTargetPos_d, "TargetPos");
    getStaticParam(&mStopSpeedRatio_s, "StopSpeedRatio");
    getStaticParam(&mStopRotSpeedRatio_s, "StopRotSpeedRatio");
    getStaticParam(&mJumpGravity_s, "JumpGravity");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mRotRatio_s, "RotRatio");
    getStaticParam(&mCheckRotEvent_s, "CheckRotEvent");
}

void BackStepBase::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
