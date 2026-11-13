#include "Game/Actor/Player/Action/actionPlayerCutDash.h"

namespace uking::action {

PlayerCutDash::PlayerCutDash(const InitArg& arg) : PlayerBase(arg) {}

void PlayerCutDash::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCutDash::leave_() {
    PlayerBase::leave_();
}

void PlayerCutDash::loadParams_() {
    getStaticParam(&mSearchAngle_s, "SearchAngle");
}

void PlayerCutDash::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
