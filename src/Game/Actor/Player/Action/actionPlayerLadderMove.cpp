#include "Game/Actor/Player/Action/actionPlayerLadderMove.h"

namespace uking::action {

PlayerLadderMove::PlayerLadderMove(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLadderMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLadderMove::leave_() {
    PlayerBase::leave_();
}

void PlayerLadderMove::loadParams_() {
    getStaticParam(&mDownMoveSpeed_s, "DownMoveSpeed");
}

void PlayerLadderMove::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
