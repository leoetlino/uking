#include "Game/Actor/Player/Action/actionPlayerSwimDamage.h"

namespace uking::action {

PlayerSwimDamage::PlayerSwimDamage(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSwimDamage::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSwimDamage::leave_() {
    PlayerBase::leave_();
}

void PlayerSwimDamage::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
