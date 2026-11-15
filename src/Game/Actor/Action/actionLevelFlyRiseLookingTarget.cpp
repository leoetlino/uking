#include "Game/Actor/Action/actionLevelFlyRiseLookingTarget.h"

namespace uking::action {

LevelFlyRiseLookingTarget::LevelFlyRiseLookingTarget(const InitArg& arg)
    : LevelFlyRiseLookingTargetBase(arg) {}

LevelFlyRiseLookingTarget::~LevelFlyRiseLookingTarget() = default;

bool LevelFlyRiseLookingTarget::init_(sead::Heap* heap) {
    return LevelFlyRiseLookingTargetBase::init_(heap);
}

void LevelFlyRiseLookingTarget::enter_(ksys::act::ai::InlineParamPack* params) {
    LevelFlyRiseLookingTargetBase::enter_(params);
}

void LevelFlyRiseLookingTarget::leave_() {
    LevelFlyRiseLookingTargetBase::leave_();
}

void LevelFlyRiseLookingTarget::loadParams_() {
    LevelFlyRiseLookingTargetBase::loadParams_();
}

void LevelFlyRiseLookingTarget::calc_() {
    LevelFlyRiseLookingTargetBase::calc_();
}

}  // namespace uking::action
