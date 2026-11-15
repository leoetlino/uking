#include "Game/Actor/Action/actionLevelFlyRiseLookingTargetBase.h"

namespace uking::action {

LevelFlyRiseLookingTargetBase::LevelFlyRiseLookingTargetBase(const InitArg& arg)
    : ksys::act::ai::Action(arg) {}

LevelFlyRiseLookingTargetBase::~LevelFlyRiseLookingTargetBase() = default;

bool LevelFlyRiseLookingTargetBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void LevelFlyRiseLookingTargetBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void LevelFlyRiseLookingTargetBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void LevelFlyRiseLookingTargetBase::loadParams_() {
    getStaticParam(&mHeight_s, "Height");
    getStaticParam(&mSpeed_s, "Speed");
    getStaticParam(&mRotSpeed_s, "RotSpeed");
    getStaticParam(&mPosReduceRatio_s, "PosReduceRatio");
    getStaticParam(&mRotRatio_s, "RotRatio");
    getStaticParam(&mASName_s, "ASName");
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

void LevelFlyRiseLookingTargetBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
