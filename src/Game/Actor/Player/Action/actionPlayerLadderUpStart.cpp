#include "Game/Actor/Player/Action/actionPlayerLadderUpStart.h"

namespace uking::action {

PlayerLadderUpStart::PlayerLadderUpStart(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLadderUpStart::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLadderUpStart::leave_() {
    PlayerBase::leave_();
}

void PlayerLadderUpStart::loadParams_() {
    getStaticParam(&mJumpHeight_s, "JumpHeight");
}

void PlayerLadderUpStart::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
