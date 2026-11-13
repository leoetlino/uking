#include "Game/Actor/Player/Action/actionPlayerCutTurn.h"

namespace uking::action {

PlayerCutTurn::PlayerCutTurn(const InitArg& arg) : PlayerBase(arg) {}

PlayerCutTurn::~PlayerCutTurn() = default;

void PlayerCutTurn::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCutTurn::leave_() {
    PlayerBase::leave_();
}

void PlayerCutTurn::loadParams_() {
    getStaticParam(&mAttackRatioNSword_s, "AttackRatioNSword");
    getStaticParam(&mAttackRatioLSword_s, "AttackRatioLSword");
    getStaticParam(&mAttackRatioSpear_s, "AttackRatioSpear");
    getStaticParam(&mEnergyAttack_s, "EnergyAttack");
    getStaticParam(&mEnergyChargeStart_s, "EnergyChargeStart");
    getStaticParam(&mRangeDiam_s, "RangeDiam");
    getStaticParam(&mRangeDiamAdd_s, "RangeDiamAdd");
    getStaticParam(&mMaxChargeLvNSword_s, "MaxChargeLvNSword");
    getStaticParam(&mRangeDiamAddNSword_s, "RangeDiamAddNSword");
}

void PlayerCutTurn::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
