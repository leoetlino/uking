#include "Game/Actor/Player/Action/actionPlayerSwitchHang.h"

namespace uking::action {

PlayerSwitchHang::PlayerSwitchHang(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSwitchHang::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSwitchHang::leave_() {
    PlayerBase::leave_();
}

void PlayerSwitchHang::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
