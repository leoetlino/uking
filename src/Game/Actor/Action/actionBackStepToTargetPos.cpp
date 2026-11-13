#include "Game/Actor/Action/actionBackStepToTargetPos.h"

namespace uking::action {

BackStepToTargetPos::BackStepToTargetPos(const InitArg& arg) : BackStepBase(arg) {}

BackStepToTargetPos::~BackStepToTargetPos() = default;

bool BackStepToTargetPos::init_(sead::Heap* heap) {
    return BackStepBase::init_(heap);
}

void BackStepToTargetPos::enter_(ksys::act::ai::InlineParamPack* params) {
    BackStepBase::enter_(params);
}

void BackStepToTargetPos::leave_() {
    BackStepBase::leave_();
}

void BackStepToTargetPos::loadParams_() {
    BackStepBase::loadParams_();
    getStaticParam(&mIsJumpHeightFromHigherPos_s, "IsJumpHeightFromHigherPos");
    getStaticParam(&mStartAS_s, "StartAS");
    getStaticParam(&mLoopAS_s, "LoopAS");
    getStaticParam(&mPreLandAS_s, "PreLandAS");
    getStaticParam(&mEndAS_s, "EndAS");
}

void BackStepToTargetPos::calc_() {
    BackStepBase::calc_();
}

}  // namespace uking::action
