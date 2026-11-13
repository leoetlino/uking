#include "Game/Actor/Player/Action/actionPlayerGrabUpAnmStop.h"

namespace uking::action {

PlayerGrabUpAnmStop::PlayerGrabUpAnmStop(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGrabUpAnmStop::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGrabUpAnmStop::leave_() {
    PlayerBase::leave_();
}

void PlayerGrabUpAnmStop::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
