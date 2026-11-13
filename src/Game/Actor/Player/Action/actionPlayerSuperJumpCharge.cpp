#include "Game/Actor/Player/Action/actionPlayerSuperJumpCharge.h"

namespace uking::action {

PlayerSuperJumpCharge::PlayerSuperJumpCharge(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSuperJumpCharge::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSuperJumpCharge::leave_() {
    PlayerBase::leave_();
}

void PlayerSuperJumpCharge::loadParams_() {
    getStaticParam(&mChargeTime_s, "ChargeTime");
}

void PlayerSuperJumpCharge::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
