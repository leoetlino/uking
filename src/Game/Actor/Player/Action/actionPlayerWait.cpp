#include "Game/Actor/Player/Action/actionPlayerWait.h"

namespace uking::action {

PlayerWait::PlayerWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWait::leave_() {
    PlayerBase::leave_();
}

void PlayerWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
