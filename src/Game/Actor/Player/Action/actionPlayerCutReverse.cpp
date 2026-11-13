#include "Game/Actor/Player/Action/actionPlayerCutReverse.h"

namespace uking::action {

PlayerCutReverse::PlayerCutReverse(const InitArg& arg) : PlayerBase(arg) {}

void PlayerCutReverse::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCutReverse::leave_() {
    PlayerBase::leave_();
}

void PlayerCutReverse::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
