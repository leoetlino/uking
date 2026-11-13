#include "Game/Actor/Player/Action/actionPlayerSelfCamera.h"

namespace uking::action {

PlayerSelfCamera::PlayerSelfCamera(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSelfCamera::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSelfCamera::leave_() {
    PlayerBase::leave_();
}

void PlayerSelfCamera::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
