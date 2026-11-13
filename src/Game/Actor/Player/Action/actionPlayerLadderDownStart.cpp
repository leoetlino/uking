#include "Game/Actor/Player/Action/actionPlayerLadderDownStart.h"

namespace uking::action {

PlayerLadderDownStart::PlayerLadderDownStart(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLadderDownStart::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLadderDownStart::leave_() {
    PlayerBase::leave_();
}

void PlayerLadderDownStart::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
