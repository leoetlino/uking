#include "Game/Actor/Action/actionScrapEquip.h"

namespace uking::action {

ScrapEquip::ScrapEquip(const InitArg& arg) : OnetimeStopBase(arg) {}

ScrapEquip::~ScrapEquip() = default;

bool ScrapEquip::init_(sead::Heap* heap) {
    return OnetimeStopBase::init_(heap);
}

void ScrapEquip::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void ScrapEquip::leave_() {
    OnetimeStopBase::leave_();
}

void ScrapEquip::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mWeaponIdx_s, "WeaponIdx");
    getStaticParam(&mDropSpd_s, "DropSpd");
}

void ScrapEquip::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
