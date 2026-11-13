#include "Game/Actor/Player/Action/actionPlayerBase.h"

namespace uking::action {

PlayerBase::PlayerBase(const InitArg& arg) : ActionEx(arg) {}

void PlayerBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ActionEx::enter_(params);
}

void PlayerBase::leave_() {
    ActionEx::leave_();
}

void PlayerBase::calc_() {
    ActionEx::calc_();
}

}  // namespace uking::action
