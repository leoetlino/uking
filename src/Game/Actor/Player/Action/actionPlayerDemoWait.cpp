#include "Game/Actor/Player/Action/actionPlayerDemoWait.h"

namespace uking::action {

PlayerDemoWait::PlayerDemoWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDemoWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDemoWait::leave_() {
    PlayerBase::leave_();
}

void PlayerDemoWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
