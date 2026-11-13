#include "Game/Actor/Player/Action/actionPlayerStainCarryWait.h"

namespace uking::action {

PlayerStainCarryWait::PlayerStainCarryWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerStainCarryWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerStainCarryWait::leave_() {
    PlayerBase::leave_();
}

void PlayerStainCarryWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
