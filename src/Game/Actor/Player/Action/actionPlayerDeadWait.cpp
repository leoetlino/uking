#include "Game/Actor/Player/Action/actionPlayerDeadWait.h"

namespace uking::action {

PlayerDeadWait::PlayerDeadWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDeadWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDeadWait::leave_() {
    PlayerBase::leave_();
}

void PlayerDeadWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
