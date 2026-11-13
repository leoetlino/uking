#include "Game/Actor/Action/actionRemainsWaterBulletMoveBase.h"

namespace uking::action {

RemainsWaterBulletMoveBase::RemainsWaterBulletMoveBase(const InitArg& arg)
    : ksys::act::ai::Action(arg) {}

RemainsWaterBulletMoveBase::~RemainsWaterBulletMoveBase() = default;

bool RemainsWaterBulletMoveBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void RemainsWaterBulletMoveBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void RemainsWaterBulletMoveBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void RemainsWaterBulletMoveBase::loadParams_() {
    getStaticParam(&mSignASFrame_s, "SignASFrame");
    getStaticParam(&mMaxRotSpd_s, "MaxRotSpd");
    getStaticParam(&mMinRotSpd_s, "MinRotSpd");
    getStaticParam(&mEndTimer_s, "EndTimer");
    getStaticParam(&mIgnroeWater_s, "IgnroeWater");
    getStaticParam(&mIgnoreGravity_s, "IgnoreGravity");
    getStaticParam(&mUseParentRevDirRot_s, "UseParentRevDirRot");
    getStaticParam(&mSignASName_s, "SignASName");
}

void RemainsWaterBulletMoveBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
