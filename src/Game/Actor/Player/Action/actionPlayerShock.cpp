#include "Game/Actor/Player/Action/actionPlayerShock.h"

namespace uking::action {

PlayerShock::PlayerShock(const InitArg& arg) : PlayerBase(arg) {}

void PlayerShock::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerShock::leave_() {
    PlayerBase::leave_();
}

void PlayerShock::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
