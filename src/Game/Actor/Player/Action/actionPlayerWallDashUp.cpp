#include "Game/Actor/Player/Action/actionPlayerWallDashUp.h"

namespace uking::action {

PlayerWallDashUp::PlayerWallDashUp(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWallDashUp::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWallDashUp::leave_() {
    PlayerBase::leave_();
}

void PlayerWallDashUp::loadParams_() {
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mMinSpeedF_s, "MinSpeedF");
    getStaticParam(&mMaxSpeedF_s, "MaxSpeedF");
}

void PlayerWallDashUp::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
