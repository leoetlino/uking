#include "Game/Actor/Action/actionGetWeaponEquip.h"

namespace uking::action {

GetWeaponEquip::GetWeaponEquip(const InitArg& arg) : GetItemBase(arg) {}

void GetWeaponEquip::enter_(ksys::act::ai::InlineParamPack* params) {
    GetItemBase::enter_(params);
}

void GetWeaponEquip::calc_() {
    GetItemBase::calc_();
}

}  // namespace uking::action
