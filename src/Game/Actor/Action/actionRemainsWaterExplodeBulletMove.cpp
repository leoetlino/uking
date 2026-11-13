#include "Game/Actor/Action/actionRemainsWaterExplodeBulletMove.h"

namespace uking::action {

RemainsWaterExplodeBulletMove::RemainsWaterExplodeBulletMove(const InitArg& arg)
    : RemainsWaterBulletMoveBase(arg) {}

RemainsWaterExplodeBulletMove::~RemainsWaterExplodeBulletMove() = default;

bool RemainsWaterExplodeBulletMove::init_(sead::Heap* heap) {
    return RemainsWaterBulletMoveBase::init_(heap);
}

void RemainsWaterExplodeBulletMove::enter_(ksys::act::ai::InlineParamPack* params) {
    RemainsWaterBulletMoveBase::enter_(params);
}

void RemainsWaterExplodeBulletMove::leave_() {
    RemainsWaterBulletMoveBase::leave_();
}

void RemainsWaterExplodeBulletMove::loadParams_() {
    RemainsWaterBulletMoveBase::loadParams_();
    getStaticParam(&mMaxSpeed_s, "MaxSpeed");
    getStaticParam(&mCloseRadius_s, "CloseRadius");
    getStaticParam(&mChaseAngleMulRate_s, "ChaseAngleMulRate");
    getStaticParam(&mFarRadius_s, "FarRadius");
    getStaticParam(&mChaseRotSpdRate_s, "ChaseRotSpdRate");
    getStaticParam(&mChaseSpdRate_s, "ChaseSpdRate");
    getMapUnitParam(&mRemainsWaterBulletAngle_m, "RemainsWaterBulletAngle");
    getMapUnitParam(&mRemainsWaterBulletOffset_m, "RemainsWaterBulletOffset");
}

void RemainsWaterExplodeBulletMove::calc_() {
    RemainsWaterBulletMoveBase::calc_();
}

}  // namespace uking::action
