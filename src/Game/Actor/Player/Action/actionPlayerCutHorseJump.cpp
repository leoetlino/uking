#include "Game/Actor/Player/Action/actionPlayerCutHorseJump.h"

namespace uking::action {

PlayerCutHorseJump::PlayerCutHorseJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerCutHorseJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCutHorseJump::leave_() {
    PlayerBase::leave_();
}

void PlayerCutHorseJump::loadParams_() {
    getStaticParam(&mAttackRate_s, "AttackRate");
    getStaticParam(&mFallSpAttackHeight_s, "FallSpAttackHeight");
    getStaticParam(&mFallSpAttackRadiusMin_s, "FallSpAttackRadiusMin");
    getStaticParam(&mFallSpAttackRadiusMax_s, "FallSpAttackRadiusMax");
    getStaticParam(&mFallSpAttackRadiusAdd_s, "FallSpAttackRadiusAdd");
    getStaticParam(&mFallSpAttackRadiusAddLSword_s, "FallSpAttackRadiusAddLSword");
    getStaticParam(&mFallSpAttackCheckUnderDist_s, "FallSpAttackCheckUnderDist");
    getStaticParam(&mFallSpLargeAttackRadius_s, "FallSpLargeAttackRadius");
    getStaticParam(&mRumbleType_s, "RumbleType");
    getStaticParam(&mRumblePowerMin_s, "RumblePowerMin");
    getStaticParam(&mRumblePowerMax_s, "RumblePowerMax");
    getStaticParam(&mParashawlInvalidTime_s, "ParashawlInvalidTime");
}

void PlayerCutHorseJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
