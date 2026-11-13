#include "Game/Actor/Player/Action/actionPlayerDemoAirWait.h"

namespace uking::action {

PlayerDemoAirWait::PlayerDemoAirWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDemoAirWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDemoAirWait::leave_() {
    PlayerBase::leave_();
}

void PlayerDemoAirWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
