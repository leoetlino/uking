#include "Game/Actor/Player/Action/actionPlayerWakeBoard.h"

namespace uking::action {

PlayerWakeBoard::PlayerWakeBoard(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWakeBoard::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWakeBoard::leave_() {
    PlayerBase::leave_();
}

void PlayerWakeBoard::loadParams_() {}

void PlayerWakeBoard::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
