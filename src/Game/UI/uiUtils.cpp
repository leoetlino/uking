#include "Game/UI/uiUtils.h"
#include <Byaml/Byaml.h>
#include "Game/AOC/aocHardModeManager.h"
#include "Game/Actor/actUtils.h"
#include "Game/Actor/actWeapon.h"
#include "Game/CreatePlayerEquipActorMgr.h"
#include "Game/DamageInfoMgr.h"
#include "Game/UI/uiPauseMenuDataMgr.h"
#include "KingSystem/ActorSystem/actInfoCommon.h"
#include "KingSystem/ActorSystem/actInfoData.h"
#include "KingSystem/GameData/gdtCommonFlagsUtils.h"

namespace uking::ui {

bool isMasterSwordItem(const PouchItem& item) {
    return item.getType() == PouchItemType::Sword && isMasterSwordActorName(item.getName());
}

int getItemHitPointRecover(const sead::SafeString& name) {
    auto* info = ksys::act::InfoData::instance();
    if (!info)
        return 0;

    al::ByamlIter iter;
    if (!info->getActorIter(&iter, name.cstr()))
        return 0;
    if (!info->hasTag(iter, ksys::act::tags::CureItem))
        return 0;
    if (!info->hasTag(iter, ksys::act::tags::CanUse))
        return 0;

    int value = ksys::act::getCureItemHitPointRecover(iter);

    using HardModeMgr = uking::aoc::HardModeManager;
    if (HardModeMgr::instance() &&
        HardModeMgr::instance()->checkFlag(HardModeMgr::Flag::EnableHardMode) &&
        HardModeMgr::instance()->isHardModeChangeOn(HardModeMgr::HardModeChange::NerfHpRestore)) {
        HardModeMgr::instance()->nerfHpRestore(&value);
    }

    return value;
}

void getWeaponStats(const PouchItem& item, WeaponStats* stats) {
    stats->durability = item.getValue();
    auto& modifier = stats->modifier;
    modifier.fromItem(item);

    auto* info = ksys::act::InfoData::instance();
    if (!info)
        return;

    if (item.getType() == PouchItemType::Shield) {
        stats->power = ksys::act::getWeaponCommonGuardPower(info, item.getName().cstr());
        stats->power += modifier.flags.isOn(act::WeaponModifier::AddGuard) ? modifier.value : 0;

    } else if (isMasterSwordItem(item)) {
        int power = 0;
        if (item.getValue() > 0) {
            const bool is_true_form = DamageInfoMgr::instance()->isTrueFormMasterSword();
            auto* info_ = ksys::act::InfoData::instance();
            const char* name = item.getName().cstr();
            if (is_true_form) {
                power = ksys::act::getMasterSwordTrueFormAttackPower(info_, name);
            } else {
                const auto attack = ksys::act::getAttackPower(info_, name);
                power = ksys::gdt::getFlag_MasterSword_Add_Power() + attack;
            }
        }
        stats->power = power;

    } else if (act::isOneHitObliteratorActorName(item.getName())) {
        stats->power = DamageInfoMgr::instance()->isOneHitObliteratorActive() ? 99999 : 1;
    } else {
        stats->power =
            ksys::act::getAttackPower(ksys::act::InfoData::instance(), item.getName().cstr());
    }

    stats->power += modifier.flags.isOn(act::WeaponModifier::AddAtk) ? modifier.value : 0;

    if (item.getType() == PouchItemType::Bow) {
        if (modifier.flags.isOn(act::WeaponModifier::AddSpreadFire))
            stats->bow_add_value = modifier.value;
        else
            stats->bow_add_value = getBowActorInfoAddValue(item.getName());
    }
}

int getBowActorInfoAddValue(const sead::SafeString& name) {
    auto* info = ksys::act::InfoData::instance();
    al::ByamlIter iter;
    if (!info)
        return 0;

    if (!info->getActorIter(&iter, name.cstr()))
        return 0;

    if (ksys::act::getBowIsLeadShot(iter))
        return ksys::act::getBowLeadShotNum(iter);

    if (ksys::act::getBowIsRapidFire(iter))
        return ksys::act::getBowRapidFireNum(iter);

    return 1;
}

int getWeaponInventoryLife(const sead::SafeString& name) {
    auto* info = ksys::act::InfoData::instance();
    if (!info)
        return 0;
    const int life = ksys::act::getGeneralLife(info, name.cstr());
    return act::WeaponModifierInfo::getLifeMultiplier() * life;
}

bool isMasterSwordActorName(const sead::SafeString& name) {
    return name == "Weapon_Sword_070";
}

CreateEquipmentSlot getCreateEquipmentSlot(ui::PouchItemType type) {
    switch (type) {
    case ui::PouchItemType::Sword:
        return CreateEquipmentSlot::WeaponSword;
    case ui::PouchItemType::Bow:
        return CreateEquipmentSlot::WeaponBow;
    case ui::PouchItemType::Shield:
        return CreateEquipmentSlot::WeaponShield;
    case ui::PouchItemType::ArmorHead:
        return CreateEquipmentSlot::ArmorHead;
    case ui::PouchItemType::ArmorUpper:
        return CreateEquipmentSlot::ArmorUpper;
    case ui::PouchItemType::ArmorLower:
        return CreateEquipmentSlot::ArmorLower;
    default:
        return CreateEquipmentSlot::Length;
    }
}

ui::EquipmentSlot getEquipmentSlot(CreateEquipmentSlot slot) {
    switch (slot) {
    case CreateEquipmentSlot::WeaponSword:
        return ui::EquipmentSlot::WeaponRight;
    case CreateEquipmentSlot::WeaponShield:
        return ui::EquipmentSlot::WeaponLeft;
    case CreateEquipmentSlot::WeaponBow:
        return ui::EquipmentSlot::WeaponBow;
    case CreateEquipmentSlot::ArmorHead:
        return ui::EquipmentSlot::ArmorHead;
    case CreateEquipmentSlot::ArmorUpper:
        return ui::EquipmentSlot::ArmorUpper;
    case CreateEquipmentSlot::ArmorLower:
        return ui::EquipmentSlot::ArmorLower;
    default:
        return ui::EquipmentSlot::Invalid;
    }
}

bool createEquipmentFromItem(const ui::PouchItem* item, const sead::SafeString& caller) {
    if (!item) {
        return false;
    }

    auto* mgr = CreatePlayerEquipActorMgr::instance();
    if (!mgr) {
        return false;
    }

    auto type = item->getType();
    auto slot = getCreateEquipmentSlot(type);
    int slot_idx = (int)slot;

    if (slot <= CreateEquipmentSlot::WeaponBow) {
        act::WeaponModifierInfo modifier(*item);
        mgr->requestCreateWeapon(slot_idx, item->getName(), item->getValue(), &modifier, caller);
        return true;
    }

    if (slot <= CreateEquipmentSlot::ArmorLower) {
        mgr->requestCreateArmor(slot_idx, item->getName(), item->getValue(), caller);
        return true;
    }

    return false;
}

}  // namespace uking::ui
