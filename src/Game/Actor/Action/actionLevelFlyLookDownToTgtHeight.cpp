#include "Game/Actor/Action/actionLevelFlyLookDownToTgtHeight.h"

namespace uking::action {

LevelFlyLookDownToTgtHeight::LevelFlyLookDownToTgtHeight(const InitArg& arg)
    : LevelFlyRiseLookingTargetBase(arg) {}

LevelFlyLookDownToTgtHeight::~LevelFlyLookDownToTgtHeight() = default;

bool LevelFlyLookDownToTgtHeight::init_(sead::Heap* heap) {
    return LevelFlyRiseLookingTargetBase::init_(heap);
}

void LevelFlyLookDownToTgtHeight::enter_(ksys::act::ai::InlineParamPack* params) {
    LevelFlyRiseLookingTargetBase::enter_(params);
}

void LevelFlyLookDownToTgtHeight::leave_() {
    LevelFlyRiseLookingTargetBase::leave_();
}

void LevelFlyLookDownToTgtHeight::loadParams_() {
    LevelFlyRiseLookingTargetBase::loadParams_();
}

void LevelFlyLookDownToTgtHeight::calc_() {
    LevelFlyRiseLookingTargetBase::calc_();
}

}  // namespace uking::action
