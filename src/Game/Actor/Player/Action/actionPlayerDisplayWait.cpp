#include "Game/Actor/Player/Action/actionPlayerDisplayWait.h"

namespace uking::action {

PlayerDisplayWait::PlayerDisplayWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDisplayWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDisplayWait::leave_() {
    PlayerBase::leave_();
}

void PlayerDisplayWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
