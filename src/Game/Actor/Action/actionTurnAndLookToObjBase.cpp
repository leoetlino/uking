#include "Game/Actor/Action/actionTurnAndLookToObjBase.h"

namespace uking::action {

TurnAndLookToObjBase::TurnAndLookToObjBase(const InitArg& arg) : PlayerBase(arg) {}

TurnAndLookToObjBase::~TurnAndLookToObjBase() = default;

bool TurnAndLookToObjBase::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void TurnAndLookToObjBase::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void TurnAndLookToObjBase::leave_() {
    PlayerBase::leave_();
}

void TurnAndLookToObjBase::loadParams_() {
    getDynamicParam(&mObjectId_d, "ObjectId");
    getDynamicParam(&mFaceId_d, "FaceId");
    getDynamicParam(&mTurnDirection_d, "TurnDirection");
    getDynamicParam(&mIsValid_d, "IsValid");
    getDynamicParam(&mActorName_d, "ActorName");
    getDynamicParam(&mUniqueName_d, "UniqueName");
    getDynamicParam(&mPosOffset_d, "PosOffset");
    getDynamicParam(&mTurnPosition_d, "TurnPosition");
}

void TurnAndLookToObjBase::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
