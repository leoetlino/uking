#include "Game/Actor/Player/Action/actionPlayerElectric.h"

namespace uking::action {

PlayerElectric::PlayerElectric(const InitArg& arg) : PlayerBase(arg) {}

void PlayerElectric::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerElectric::leave_() {
    PlayerBase::leave_();
}

void PlayerElectric::loadParams_() {
    getStaticParam(&mJumpSpeedF_s, "JumpSpeedF");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
}

void PlayerElectric::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
