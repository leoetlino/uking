#include "Game/Actor/Player/Action/actionPlayerSubjectWait.h"

namespace uking::action {

PlayerSubjectWait::PlayerSubjectWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSubjectWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSubjectWait::leave_() {
    PlayerBase::leave_();
}

void PlayerSubjectWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
