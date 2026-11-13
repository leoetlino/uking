#include "Game/Actor/Player/Action/actionPlayerGrabStand.h"

namespace uking::action {

PlayerGrabStand::PlayerGrabStand(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGrabStand::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGrabStand::leave_() {
    PlayerBase::leave_();
}

void PlayerGrabStand::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
