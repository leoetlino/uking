#include "Game/Actor/Player/Action/actionPlayerLand.h"

namespace uking::action {

PlayerLand::PlayerLand(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLand::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLand::leave_() {
    PlayerBase::leave_();
}

void PlayerLand::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
