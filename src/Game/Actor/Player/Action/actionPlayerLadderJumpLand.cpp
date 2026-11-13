#include "Game/Actor/Player/Action/actionPlayerLadderJumpLand.h"

namespace uking::action {

PlayerLadderJumpLand::PlayerLadderJumpLand(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLadderJumpLand::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLadderJumpLand::leave_() {
    PlayerBase::leave_();
}

void PlayerLadderJumpLand::loadParams_() {
    getDynamicParam(&mMoveDir_d, "MoveDir");
}

void PlayerLadderJumpLand::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
