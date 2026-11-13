#include "Game/Actor/Player/Action/actionPlayerBase.h"

namespace uking::action {

PlayerBase::PlayerBase(const InitArg& arg) : act::ActionEx(arg) {}

void PlayerBase::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void PlayerBase::leave_() {
    act::ActionEx::leave_();
}

void PlayerBase::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
