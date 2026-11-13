#include "Game/Actor/Player/Action/actionPlayerLadderToClimb.h"

namespace uking::action {

PlayerLadderToClimb::PlayerLadderToClimb(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLadderToClimb::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLadderToClimb::leave_() {
    PlayerBase::leave_();
}

void PlayerLadderToClimb::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
