#include "Game/Actor/Player/Action/actionPlayerGrabReady.h"

namespace uking::action {

PlayerGrabReady::PlayerGrabReady(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGrabReady::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGrabReady::leave_() {
    PlayerBase::leave_();
}

void PlayerGrabReady::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
