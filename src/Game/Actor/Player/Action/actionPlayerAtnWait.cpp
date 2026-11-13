#include "Game/Actor/Player/Action/actionPlayerAtnWait.h"

namespace uking::action {

PlayerAtnWait::PlayerAtnWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerAtnWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerAtnWait::leave_() {
    PlayerBase::leave_();
}

void PlayerAtnWait::loadParams_() {
    getStaticParam(&mAtnTurnDiffAng_s, "AtnTurnDiffAng");
}

void PlayerAtnWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
