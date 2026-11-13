#include "Game/Actor/Player/Action/actionPlayerIceBreak.h"

namespace uking::action {

PlayerIceBreak::PlayerIceBreak(const InitArg& arg) : PlayerBase(arg) {}

void PlayerIceBreak::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerIceBreak::leave_() {
    PlayerBase::leave_();
}

void PlayerIceBreak::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
