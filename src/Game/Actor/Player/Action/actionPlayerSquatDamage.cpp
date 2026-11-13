#include "Game/Actor/Player/Action/actionPlayerSquatDamage.h"

namespace uking::action {

PlayerSquatDamage::PlayerSquatDamage(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSquatDamage::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSquatDamage::leave_() {
    PlayerBase::leave_();
}

void PlayerSquatDamage::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
