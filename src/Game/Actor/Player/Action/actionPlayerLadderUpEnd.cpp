#include "Game/Actor/Player/Action/actionPlayerLadderUpEnd.h"

namespace uking::action {

PlayerLadderUpEnd::PlayerLadderUpEnd(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLadderUpEnd::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLadderUpEnd::leave_() {
    PlayerBase::leave_();
}

void PlayerLadderUpEnd::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
