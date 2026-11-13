#include "Game/Actor/Player/Action/actionPlayerCaught.h"

namespace uking::action {

PlayerCaught::PlayerCaught(const InitArg& arg) : PlayerBase(arg) {}

PlayerCaught::~PlayerCaught() = default;

void PlayerCaught::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCaught::leave_() {
    PlayerBase::leave_();
}

void PlayerCaught::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
