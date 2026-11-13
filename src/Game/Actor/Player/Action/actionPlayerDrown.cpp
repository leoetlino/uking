#include "Game/Actor/Player/Action/actionPlayerDrown.h"

namespace uking::action {

PlayerDrown::PlayerDrown(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDrown::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDrown::leave_() {
    PlayerBase::leave_();
}

void PlayerDrown::loadParams_() {}

void PlayerDrown::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
