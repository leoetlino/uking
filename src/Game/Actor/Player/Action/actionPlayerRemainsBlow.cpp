#include "Game/Actor/Player/Action/actionPlayerRemainsBlow.h"

namespace uking::action {

PlayerRemainsBlow::PlayerRemainsBlow(const InitArg& arg) : PlayerBase(arg) {}

void PlayerRemainsBlow::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerRemainsBlow::leave_() {
    PlayerBase::leave_();
}

void PlayerRemainsBlow::loadParams_() {
    getStaticParam(&mInitSpeed_s, "InitSpeed");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
}

void PlayerRemainsBlow::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
