#include "Game/Actor/Player/Action/actionPlayerLadderDownEnd.h"

namespace uking::action {

PlayerLadderDownEnd::PlayerLadderDownEnd(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLadderDownEnd::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLadderDownEnd::leave_() {
    PlayerBase::leave_();
}

void PlayerLadderDownEnd::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
