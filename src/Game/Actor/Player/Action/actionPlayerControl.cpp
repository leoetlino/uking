#include "Game/Actor/Player/Action/actionPlayerControl.h"

namespace uking::action {

PlayerControl::PlayerControl(const InitArg& arg) : PlayerBase(arg) {}

void PlayerControl::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerControl::leave_() {
    PlayerBase::leave_();
}

void PlayerControl::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
