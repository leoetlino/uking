#include "Game/Actor/Player/Action/actionPlayerAtnMove.h"

namespace uking::action {

PlayerAtnMove::PlayerAtnMove(const InitArg& arg) : PlayerBase(arg) {}

void PlayerAtnMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerAtnMove::leave_() {
    PlayerBase::leave_();
}

void PlayerAtnMove::loadParams_() {}

void PlayerAtnMove::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
