#include "Game/Actor/Player/Action/actionPlayerHell.h"

namespace uking::action {

PlayerHell::PlayerHell(const InitArg& arg) : PlayerBase(arg) {}

void PlayerHell::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerHell::leave_() {
    PlayerBase::leave_();
}

void PlayerHell::loadParams_() {
    getDynamicParam(&mIsNoDamage_d, "IsNoDamage");
}

void PlayerHell::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
