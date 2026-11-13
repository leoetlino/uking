#include "Game/Actor/Player/Action/actionPlayerGuardJust.h"

namespace uking::action {

PlayerGuardJust::PlayerGuardJust(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGuardJust::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGuardJust::leave_() {
    PlayerBase::leave_();
}

void PlayerGuardJust::loadParams_() {
    getStaticParam(&mForceSlowTime_s, "ForceSlowTime");
}

void PlayerGuardJust::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
