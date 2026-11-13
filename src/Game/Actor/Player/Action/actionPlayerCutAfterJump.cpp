#include "Game/Actor/Player/Action/actionPlayerCutAfterJump.h"

namespace uking::action {

PlayerCutAfterJump::PlayerCutAfterJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerCutAfterJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCutAfterJump::leave_() {
    PlayerBase::leave_();
}

void PlayerCutAfterJump::loadParams_() {}

void PlayerCutAfterJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
