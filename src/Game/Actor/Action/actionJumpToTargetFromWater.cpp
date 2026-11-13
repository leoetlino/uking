#include "Game/Actor/Action/actionJumpToTargetFromWater.h"

namespace uking::action {

JumpToTargetFromWater::JumpToTargetFromWater(const InitArg& arg) : JumpToTargetBase(arg) {}

JumpToTargetFromWater::~JumpToTargetFromWater() = default;

bool JumpToTargetFromWater::init_(sead::Heap* heap) {
    return JumpToTargetBase::init_(heap);
}

void JumpToTargetFromWater::enter_(ksys::act::ai::InlineParamPack* params) {
    JumpToTargetBase::enter_(params);
}

void JumpToTargetFromWater::leave_() {
    JumpToTargetBase::leave_();
}

void JumpToTargetFromWater::loadParams_() {
    JumpToTargetBase::loadParams_();
    getStaticParam(&mFloatCycleTime_s, "FloatCycleTime");
    getStaticParam(&mFloatDepth_s, "FloatDepth");
    getStaticParam(&mFloatRadius_s, "FloatRadius");
    getStaticParam(&mPreJumpAS_s, "PreJumpAS");
    getStaticParam(&mJumpAS_s, "JumpAS");
    getStaticParam(&mLandAS_s, "LandAS");
}

void JumpToTargetFromWater::calc_() {
    JumpToTargetBase::calc_();
}

}  // namespace uking::action
