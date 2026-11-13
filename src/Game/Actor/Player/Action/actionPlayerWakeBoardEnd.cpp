#include "Game/Actor/Player/Action/actionPlayerWakeBoardEnd.h"

namespace uking::action {

PlayerWakeBoardEnd::PlayerWakeBoardEnd(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWakeBoardEnd::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWakeBoardEnd::leave_() {
    PlayerBase::leave_();
}

void PlayerWakeBoardEnd::loadParams_() {}

void PlayerWakeBoardEnd::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
