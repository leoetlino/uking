#include "Game/Actor/Action/actionPunchAttack.h"

namespace uking::action {

PunchAttack::PunchAttack(const InitArg& arg) : OnetimeStopBase(arg) {}

PunchAttack::~PunchAttack() = default;

bool PunchAttack::init_(sead::Heap* heap) {
    return OnetimeStopBase::init_(heap);
}

void PunchAttack::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void PunchAttack::leave_() {
    OnetimeStopBase::leave_();
}

void PunchAttack::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mAttackIntensity_s, "AttackIntensity");
    getStaticParam(&mIsGuardPierce_s, "IsGuardPierce");
    getStaticParam(&mIsForceGuardBreak_s, "IsForceGuardBreak");
    getStaticParam(&mIsIniviciblePierce_s, "IsIniviciblePierce");
    getStaticParam(&mIsImpulseLarge_s, "IsImpulseLarge");
    getStaticParam(&mIsHeavy_s, "IsHeavy");
    getStaticParam(&mIsHammer_s, "IsHammer");
    getStaticParam(&mASName_s, "ASName");
    // FIXME: CALL _ZN4sead17StringBuilderBaseIcE6formatEPKcz @ 0x7100b0d550
    // FIXME: CALL _ZN4sead17StringBuilderBaseIcE6formatEPKcz @ 0x7100b0d550
    // FIXME: CALL _ZN4sead17StringBuilderBaseIcE6formatEPKcz @ 0x7100b0d550
}

void PunchAttack::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
