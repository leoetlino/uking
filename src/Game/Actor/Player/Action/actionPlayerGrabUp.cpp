#include "Game/Actor/Player/Action/actionPlayerGrabUp.h"

namespace uking::action {

PlayerGrabUp::PlayerGrabUp(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGrabUp::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGrabUp::leave_() {
    PlayerBase::leave_();
}

void PlayerGrabUp::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
