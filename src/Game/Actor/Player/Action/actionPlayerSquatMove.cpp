#include "Game/Actor/Player/Action/actionPlayerSquatMove.h"

namespace uking::action {

PlayerSquatMove::PlayerSquatMove(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSquatMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSquatMove::leave_() {
    PlayerBase::leave_();
}

void PlayerSquatMove::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
