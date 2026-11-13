#include "Game/Actor/Action/actionThrowWeapon.h"

namespace uking::action {

ThrowWeapon::ThrowWeapon(const InitArg& arg) : OnetimeStopBase(arg) {}

ThrowWeapon::~ThrowWeapon() = default;

void ThrowWeapon::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void ThrowWeapon::leave_() {
    OnetimeStopBase::leave_();
}

void ThrowWeapon::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mWeaponIdx_s, "WeaponIdx");
    getStaticParam(&mSpeedMin_s, "SpeedMin");
    getStaticParam(&mSpeedMax_s, "SpeedMax");
    getStaticParam(&mThrowAng_s, "ThrowAng");
    getStaticParam(&mThrowBoomerangAng_s, "ThrowBoomerangAng");
    getStaticParam(&mThrowBoomerangSpeedMax_s, "ThrowBoomerangSpeedMax");
    getDynamicParam(&mTargetPos_d, "TargetPos");
    getStaticParam(&mIsForceDead_s, "IsForceDead");
}

void ThrowWeapon::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
