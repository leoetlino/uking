#include "Game/Actor/Player/Action/actionPlayerGuardBreak.h"

namespace uking::action {

PlayerGuardBreak::PlayerGuardBreak(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGuardBreak::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGuardBreak::leave_() {
    PlayerBase::leave_();
}

void PlayerGuardBreak::loadParams_() {}

void PlayerGuardBreak::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
