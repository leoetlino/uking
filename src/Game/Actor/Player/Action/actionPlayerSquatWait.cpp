#include "Game/Actor/Player/Action/actionPlayerSquatWait.h"

namespace uking::action {

PlayerSquatWait::PlayerSquatWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSquatWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSquatWait::leave_() {
    PlayerBase::leave_();
}

void PlayerSquatWait::loadParams_() {
    getStaticParam(&mWaitTime_s, "WaitTime");
    getStaticParam(&mAtnTurnDiffAng_s, "AtnTurnDiffAng");
}

void PlayerSquatWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
