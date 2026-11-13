#include "Game/Actor/Action/actionRagdollGetUpBase.h"

namespace uking::action {

RagdollGetUpBase::RagdollGetUpBase(const InitArg& arg) : ksys::act::ai::Action(arg) {}

RagdollGetUpBase::~RagdollGetUpBase() = default;

bool RagdollGetUpBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void RagdollGetUpBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void RagdollGetUpBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void RagdollGetUpBase::loadParams_() {
    getStaticParam(&mTime_s, "Time");
    getStaticParam(&mInWaterDownTime_s, "InWaterDownTime");
    getStaticParam(&mForceFinishTime_s, "ForceFinishTime");
    getStaticParam(&mOnGroundDownTime_s, "OnGroundDownTime");
    getStaticParam(&mStartUpdateFriction_s, "StartUpdateFriction");
    getStaticParam(&mWeaponDropSpeedXZ_s, "WeaponDropSpeedXZ");
    getStaticParam(&mWeaponDropSpeedY_s, "WeaponDropSpeedY");
    getStaticParam(&mGetUpGroundAngle_s, "GetUpGroundAngle");
    getStaticParam(&mForceEndWaterDepth_s, "ForceEndWaterDepth");
    getStaticParam(&mIsWaitAS_s, "IsWaitAS");
    getStaticParam(&mIsItemDrop_s, "IsItemDrop");
    getStaticParam(&mIsCheckVibrate_s, "IsCheckVibrate");
    getStaticParam(&mASName_s, "ASName");
    getStaticParam(&mPosBaseRagdollRbName_s, "PosBaseRagdollRbName");
    getStaticParam(&mStableASName_s, "StableASName");
    getStaticParam(&mDownBackCtrlOffset_s, "DownBackCtrlOffset");
    getStaticParam(&mDownFrontCtrlOffset_s, "DownFrontCtrlOffset");
    getAITreeVariable(&mCRBOffsetUnit_a, "CRBOffsetUnit");
}

void RagdollGetUpBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
