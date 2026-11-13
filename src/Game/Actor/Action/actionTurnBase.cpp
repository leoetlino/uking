#include "Game/Actor/Action/actionTurnBase.h"

namespace uking::action {

TurnBase::TurnBase(const InitArg& arg) : act::ActionEx(arg) {}

TurnBase::~TurnBase() = default;

void TurnBase::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void TurnBase::leave_() {
    act::ActionEx::leave_();
}

void TurnBase::loadParams_() {
    getStaticParam(&mRotSpd_s, "RotSpd");
    getStaticParam(&mFinRotate_s, "FinRotate");
    getStaticParam(&mPosReduceRatio_s, "PosReduceRatio");
    getStaticParam(&mBaseRotRatio_s, "BaseRotRatio");
    getStaticParam(&mIsFollowGround_s, "IsFollowGround");
    getStaticParam(&mIsChangeable_s, "IsChangeable");
    getDynamicParam(&mTargetPos_d, "TargetPos");
    getStaticParam(&mRotMinSpeedRatio_s, "RotMinSpeedRatio");
}

void TurnBase::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
