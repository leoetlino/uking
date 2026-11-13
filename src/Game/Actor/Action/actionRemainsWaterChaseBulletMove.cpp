#include "Game/Actor/Action/actionRemainsWaterChaseBulletMove.h"

namespace uking::action {

RemainsWaterChaseBulletMove::RemainsWaterChaseBulletMove(const InitArg& arg)
    : RemainsWaterBulletMoveBase(arg) {}

RemainsWaterChaseBulletMove::~RemainsWaterChaseBulletMove() = default;

bool RemainsWaterChaseBulletMove::init_(sead::Heap* heap) {
    return RemainsWaterBulletMoveBase::init_(heap);
}

void RemainsWaterChaseBulletMove::enter_(ksys::act::ai::InlineParamPack* params) {
    RemainsWaterBulletMoveBase::enter_(params);
}

void RemainsWaterChaseBulletMove::leave_() {
    RemainsWaterBulletMoveBase::leave_();
}

void RemainsWaterChaseBulletMove::loadParams_() {
    RemainsWaterBulletMoveBase::loadParams_();
    getStaticParam(&mBaseChaseSpd_s, "BaseChaseSpd");
    getStaticParam(&mMaxChaseSpd_s, "MaxChaseSpd");
    getStaticParam(&mChaseSpdRate_s, "ChaseSpdRate");
    getStaticParam(&mChaseAngleRate_s, "ChaseAngleRate");
    getStaticParam(&mDepthOffset_s, "DepthOffset");
    getStaticParam(&mMaxPredictFrame_s, "MaxPredictFrame");
    getStaticParam(&mMinPredictFrame_s, "MinPredictFrame");
    getStaticParam(&mStartPredictDist_s, "StartPredictDist");
    getStaticParam(&mEndPredictDist_s, "EndPredictDist");
    getStaticParam(&mWeakChaseTimer_s, "WeakChaseTimer");
    getStaticParam(&mBaseTargetOffset_s, "BaseTargetOffset");
    getStaticParam(&mBaseTargetRandOffset_s, "BaseTargetRandOffset");
    getMapUnitParam(&mRemainsWaterBulletAngle_m, "RemainsWaterBulletAngle");
    getMapUnitParam(&mRemainsWaterBulletOffset_m, "RemainsWaterBulletOffset");
}

void RemainsWaterChaseBulletMove::calc_() {
    RemainsWaterBulletMoveBase::calc_();
}

}  // namespace uking::action
