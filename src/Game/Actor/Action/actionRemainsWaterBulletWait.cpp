#include "Game/Actor/Action/actionRemainsWaterBulletWait.h"

namespace uking::action {

RemainsWaterBulletWait::RemainsWaterBulletWait(const InitArg& arg)
    : RemainsWaterBulletMoveBase(arg) {}

RemainsWaterBulletWait::~RemainsWaterBulletWait() = default;

bool RemainsWaterBulletWait::init_(sead::Heap* heap) {
    return RemainsWaterBulletMoveBase::init_(heap);
}

void RemainsWaterBulletWait::enter_(ksys::act::ai::InlineParamPack* params) {
    RemainsWaterBulletMoveBase::enter_(params);
}

void RemainsWaterBulletWait::leave_() {
    RemainsWaterBulletMoveBase::leave_();
}

void RemainsWaterBulletWait::loadParams_() {
    RemainsWaterBulletMoveBase::loadParams_();
    getStaticParam(&mMaxChaseAngle_s, "MaxChaseAngle");
    getStaticParam(&mMaxSpeed_s, "MaxSpeed");
    getStaticParam(&mChaseRate_s, "ChaseRate");
    getMapUnitParam(&mRemainsWaterBulletAngle_m, "RemainsWaterBulletAngle");
    getMapUnitParam(&mRemainsWaterBulletOffset_m, "RemainsWaterBulletOffset");
}

void RemainsWaterBulletWait::calc_() {
    RemainsWaterBulletMoveBase::calc_();
}

}  // namespace uking::action
