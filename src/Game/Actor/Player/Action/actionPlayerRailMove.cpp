#include "Game/Actor/Player/Action/actionPlayerRailMove.h"

namespace uking::action {

PlayerRailMove::PlayerRailMove(const InitArg& arg) : PlayerDestinationMoveBase(arg) {}

PlayerRailMove::~PlayerRailMove() = default;

void PlayerRailMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerDestinationMoveBase::enter_(params);
}

void PlayerRailMove::leave_() {
    PlayerDestinationMoveBase::leave_();
}

void PlayerRailMove::loadParams_() {
    PlayerDestinationMoveBase::loadParams_();
    getDynamicParam(&mRailName_d, "RailName");
}

void PlayerRailMove::calc_() {
    PlayerDestinationMoveBase::calc_();
}

}  // namespace uking::action
