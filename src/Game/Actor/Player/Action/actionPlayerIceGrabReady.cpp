#include "Game/Actor/Player/Action/actionPlayerIceGrabReady.h"

namespace uking::action {

PlayerIceGrabReady::PlayerIceGrabReady(const InitArg& arg) : PlayerBase(arg) {}

PlayerIceGrabReady::~PlayerIceGrabReady() = default;

void PlayerIceGrabReady::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerIceGrabReady::leave_() {
    PlayerBase::leave_();
}

void PlayerIceGrabReady::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
