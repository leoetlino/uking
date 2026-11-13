#include "Game/Actor/Player/Action/actionPlayerGrabWait.h"

namespace uking::action {

PlayerGrabWait::PlayerGrabWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGrabWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGrabWait::leave_() {
    PlayerBase::leave_();
}

void PlayerGrabWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
