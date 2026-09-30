#include "KingSystem/Game/Horse/Action/actionHorseMoveToTargetAction.h"

namespace uking::action {

HorseMoveToTargetAction::HorseMoveToTargetAction(const InitArg& arg) : HorseNavMeshMoveBase(arg) {}

bool HorseMoveToTargetAction::init_(sead::Heap* heap) {
    return HorseNavMeshMoveBase::init_(heap);
}

void HorseMoveToTargetAction::enter_(ksys::act::ai::InlineParamPack* params) {
    HorseNavMeshMoveBase::enter_(params);
}

void HorseMoveToTargetAction::leave_() {
    HorseNavMeshMoveBase::leave_();
}

void HorseMoveToTargetAction::loadParams_() {
    HorseNavMeshMoveBase::loadParams_();
    getStaticParam(&mIsCancelRequestedPathFirst_s, "IsCancelRequestedPathFirst");
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

void HorseMoveToTargetAction::calc_() {
    HorseNavMeshMoveBase::calc_();
}

}  // namespace uking::action
