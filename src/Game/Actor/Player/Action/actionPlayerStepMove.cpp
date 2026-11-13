#include "Game/Actor/Player/Action/actionPlayerStepMove.h"

namespace uking::action {

PlayerStepMove::PlayerStepMove(const InitArg& arg) : PlayerBase(arg) {}

void PlayerStepMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerStepMove::leave_() {
    PlayerBase::leave_();
}

void PlayerStepMove::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
