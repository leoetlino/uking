#include "Game/Actor/Player/Action/actionPlayerBackJumpLand.h"

namespace uking::action {

PlayerBackJumpLand::PlayerBackJumpLand(const InitArg& arg) : PlayerBase(arg) {}

void PlayerBackJumpLand::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerBackJumpLand::leave_() {
    PlayerBase::leave_();
}

void PlayerBackJumpLand::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
