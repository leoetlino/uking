#include "Game/Actor/Player/Action/actionPlayerNavMeshMove.h"

namespace uking::action {

PlayerNavMeshMove::PlayerNavMeshMove(const InitArg& arg) : PlayerDestinationMoveBase(arg) {}

void PlayerNavMeshMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerDestinationMoveBase::enter_(params);
}

void PlayerNavMeshMove::leave_() {
    PlayerDestinationMoveBase::leave_();
}

void PlayerNavMeshMove::loadParams_() {
    PlayerDestinationMoveBase::loadParams_();
}

void PlayerNavMeshMove::calc_() {
    PlayerDestinationMoveBase::calc_();
}

}  // namespace uking::action
