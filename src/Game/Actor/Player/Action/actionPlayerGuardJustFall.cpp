#include "Game/Actor/Player/Action/actionPlayerGuardJustFall.h"

namespace uking::action {

PlayerGuardJustFall::PlayerGuardJustFall(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGuardJustFall::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGuardJustFall::leave_() {
    PlayerBase::leave_();
}

void PlayerGuardJustFall::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
