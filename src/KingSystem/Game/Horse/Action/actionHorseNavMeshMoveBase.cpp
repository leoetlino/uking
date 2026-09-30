#include "KingSystem/Game/Horse/Action/actionHorseNavMeshMoveBase.h"

namespace ksys::game {

HorseNavMeshMoveBase::HorseNavMeshMoveBase(const InitArg& arg) : ksys::act::ai::Action(arg) {}

bool HorseNavMeshMoveBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void HorseNavMeshMoveBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void HorseNavMeshMoveBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void HorseNavMeshMoveBase::loadParams_() {
    getStaticParam(&mMinUseGear_s, "MinUseGear");
    getStaticParam(&mMaxUseGear_s, "MaxUseGear");
    getStaticParam(&mUseGearType_s, "UseGearType");
    getStaticParam(&mAutoStopAndTurnMode_s, "AutoStopAndTurnMode");
    getStaticParam(&mMinGearAtAutoGearDown_s, "MinGearAtAutoGearDown");
    getStaticParam(&mGoalDistanceTolerance_s, "GoalDistanceTolerance");
    getStaticParam(&mCanUseHorseGearInput_s, "CanUseHorseGearInput");
    getStaticParam(&mIsAutoGearDownEnabled_s, "IsAutoGearDownEnabled");
    getStaticParam(&mHasToDecelerateNearGoal_s, "HasToDecelerateNearGoal");
    getStaticParam(&mWaitUntilPathSucceeded_s, "WaitUntilPathSucceeded");
}

void HorseNavMeshMoveBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace ksys::game
