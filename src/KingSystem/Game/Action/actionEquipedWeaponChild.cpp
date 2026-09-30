#include "KingSystem/Game/Action/actionEquipedWeaponChild.h"

namespace ksys::game {

EquipedWeaponChild::EquipedWeaponChild(const InitArg& arg) : BindAction(arg) {}

void EquipedWeaponChild::enter_(ksys::act::ai::InlineParamPack* params) {
    BindAction::enter_(params);
}

void EquipedWeaponChild::leave_() {
    BindAction::leave_();
}

void EquipedWeaponChild::loadParams_() {
    BindAction::loadParams_();
    getStaticParam(&mIsChangeScale_s, "IsChangeScale");
}

}  // namespace ksys::game
