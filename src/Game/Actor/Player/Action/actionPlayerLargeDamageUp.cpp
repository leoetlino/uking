#include "Game/Actor/Player/Action/actionPlayerLargeDamageUp.h"

namespace uking::action {

PlayerLargeDamageUp::PlayerLargeDamageUp(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLargeDamageUp::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLargeDamageUp::leave_() {
    PlayerBase::leave_();
}

void PlayerLargeDamageUp::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
