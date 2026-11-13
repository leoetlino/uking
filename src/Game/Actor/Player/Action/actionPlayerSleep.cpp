#include "Game/Actor/Player/Action/actionPlayerSleep.h"

namespace uking::action {

PlayerSleep::PlayerSleep(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSleep::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSleep::leave_() {
    PlayerBase::leave_();
}

void PlayerSleep::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
