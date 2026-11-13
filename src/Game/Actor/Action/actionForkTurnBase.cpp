#include "Game/Actor/Action/actionForkTurnBase.h"

namespace uking::action {

ForkTurnBase::ForkTurnBase(const InitArg& arg) : ksys::act::ai::Action(arg) {}

ForkTurnBase::~ForkTurnBase() = default;

bool ForkTurnBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void ForkTurnBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void ForkTurnBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void ForkTurnBase::loadParams_() {
    getStaticParam(&mRotSpd_s, "RotSpd");
    getStaticParam(&mFinRotate_s, "FinRotate");
    getStaticParam(&mPosReduceRatio_s, "PosReduceRatio");
    getStaticParam(&mBaseRotRatio_s, "BaseRotRatio");
    getStaticParam(&mRotAccRatio_s, "RotAccRatio");
    getStaticParam(&mRotAccMaxSpeedRatio_s, "RotAccMaxSpeedRatio");
    getStaticParam(&mIsUpdateTarget_s, "IsUpdateTarget");
    getStaticParam(&mIsFollowGround_s, "IsFollowGround");
    getStaticParam(&mIsRotEndFinish_s, "IsRotEndFinish");
    getStaticParam(&mIsFinishForceStopRot_s, "IsFinishForceStopRot");
    getStaticParam(&mIsChangeable_s, "IsChangeable");
    getStaticParam(&mIsUpFollow_s, "IsUpFollow");
}

void ForkTurnBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
