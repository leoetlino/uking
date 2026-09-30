#include "Game/Actor/Action/actionLynelNavMeshMove.h"

namespace uking::action {

LynelNavMeshMove::LynelNavMeshMove(const InitArg& arg) : HorseNavMeshMoveBase(arg) {}

LynelNavMeshMove::~LynelNavMeshMove() = default;

bool LynelNavMeshMove::init_(sead::Heap* heap) {
    return HorseNavMeshMoveBase::init_(heap);
}

void LynelNavMeshMove::enter_(ksys::act::ai::InlineParamPack* params) {
    HorseNavMeshMoveBase::enter_(params);
}

void LynelNavMeshMove::leave_() {
    HorseNavMeshMoveBase::leave_();
}

void LynelNavMeshMove::loadParams_() {
    HorseNavMeshMoveBase::loadParams_();
    getDynamicParam(&mTargetPos_d, "TargetPos");
    // FIXME: CALL sub_710070F984 @ 0x710070f984
}

void LynelNavMeshMove::calc_() {
    HorseNavMeshMoveBase::calc_();
}

}  // namespace uking::action
