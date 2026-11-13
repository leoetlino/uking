#include "Game/Actor/Player/Action/actionPlayerPullSwordFirstFail.h"

namespace uking::action {

PlayerPullSwordFirstFail::PlayerPullSwordFirstFail(const InitArg& arg) : PlayerBase(arg) {}

void PlayerPullSwordFirstFail::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerPullSwordFirstFail::leave_() {
    PlayerBase::leave_();
}

void PlayerPullSwordFirstFail::loadParams_() {
    getStaticParam(&mFirstFailureWait_s, "FirstFailureWait");
}

void PlayerPullSwordFirstFail::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
