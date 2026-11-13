#include "Game/Actor/Player/Action/actionPlayerTreeClimb.h"

namespace uking::action {

PlayerTreeClimb::PlayerTreeClimb(const InitArg& arg) : PlayerBase(arg) {}

void PlayerTreeClimb::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerTreeClimb::leave_() {
    PlayerBase::leave_();
}

void PlayerTreeClimb::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
