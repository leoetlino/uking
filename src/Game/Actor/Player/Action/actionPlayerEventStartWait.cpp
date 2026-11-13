#include "Game/Actor/Player/Action/actionPlayerEventStartWait.h"

namespace uking::action {

PlayerEventStartWait::PlayerEventStartWait(const InitArg& arg) : PlayerBase(arg) {}

PlayerEventStartWait::~PlayerEventStartWait() = default;

void PlayerEventStartWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerEventStartWait::leave_() {
    PlayerBase::leave_();
}

void PlayerEventStartWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
