#include "KingSystem/Game/Util/ActorUtil.h"
#include <Byaml/Byaml.h>
#include <container/seadSafeArray.h>
#include <math/seadMathCalcCommon.h>
#include <random/seadGlobalRandom.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectNpc.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/ActorSystem/actActorLink.h"
#include "KingSystem/ActorSystem/actActorLinkConstDataAccess.h"
#include "KingSystem/ActorSystem/actActorParam.h"
#include "KingSystem/ActorSystem/actGParamList.h"
#include "KingSystem/ActorSystem/actInfoData.h"
#include "KingSystem/ActorSystem/actPreActor.h"
#include "KingSystem/ActorSystem/actTag.h"
#include "KingSystem/Framework/frmBaseProcLink.h"
#include "KingSystem/Game/Ecosystem/Ecosystem.h"
#include "KingSystem/Game/Rope/RopeBase.h"
#include "KingSystem/GameData/gdtManager.h"
#include "KingSystem/Map/mapPlacementMgr.h"
#include "KingSystem/World/worldManager.h"

namespace ksys::game {

namespace {

act::ActorLinkConstDataAccess getAccessor(frm::BaseProcLink* link) {
    act::ActorLinkConstDataAccess accessor;
    acquireActor(link, &accessor);
    return accessor;
}

act::ActorLinkConstDataAccess getAccessor(act::Actor* actor) {
    act::ActorLinkConstDataAccess accessor{actor};
    return accessor;
}

sead::SafeString sDefaultDropActor = "Item_Fruit_A";
sead::SafeArray<const char*, 6> sArrowTypes{{
    "NormalArrow",
    "BombArrow_A",
    "AncientArrow",
    "FireArrow",
    "IceArrow",
    "ElectricArrow",
}};
gdt::FlagHandle sAnimalMasterAppearanceHandle = gdt::InvalidHandle;
gdt::FlagHandle sFairyCountCheckHandle = gdt::InvalidHandle;
gdt::FlagHandle sIsGetStopTimerLv2Handle = gdt::InvalidHandle;

}  // namespace

bool hasTag(act::Actor* actor, const sead::SafeString& tag) {
    if (!actor)
        return false;
    return actor->getParam()->getRes().mActorLink->hasTag(tag.cstr());
}

bool hasTag(frm::BaseProcLink* link, const sead::SafeString& tag) {
    return hasTag(getAccessor(link), tag);
}

bool hasTag(const act::ActorLinkConstDataAccess& accessor, const sead::SafeString& tag) {
    return accessor.hasTag(tag.cstr());
}

bool hasTag(const sead::SafeString& actor, const sead::SafeString& tag) {
    auto* data = act::InfoData::instance();
    return data && data->hasTag(actor.cstr(), tag.cstr());
}

bool hasTag(act::Actor* actor, u32 tag) {
    return actor && actor->getParam()->getRes().mActorLink->hasTag(tag);
}

bool hasTag(frm::BaseProcLink* link, u32 tag) {
    return hasTag(getAccessor(link), tag);
}

bool hasTag(const act::ActorLinkConstDataAccess& accessor, u32 tag) {
    return accessor.hasTag(tag);
}

bool hasTag(const sead::SafeString& actor, u32 tag) {
    auto* data = act::InfoData::instance();
    return data && data->hasTag(actor.cstr(), tag);
}

bool hasOneTagAtLeast(act::Actor* actor, const sead::SafeString& tags) {
    sead::FixedSafeString<32> tag;
    for (auto it = tags.tokenBegin(","); tags.tokenEnd(",") != it; ++it) {
        it.get(&tag);
        if (hasTag(actor, tag))
            return true;
    }
    return false;
}

bool hasOneTagAtLeast(frm::BaseProcLink* link, const sead::SafeString& tags) {
    sead::FixedSafeString<32> tag;
    for (auto it = tags.tokenBegin(","); tags.tokenEnd(",") != it; ++it) {
        it.get(&tag);
        if (hasTag(link, tag))
            return true;
    }
    return false;
}

bool hasOneTagAtLeast(const act::ActorLinkConstDataAccess& accessor, const sead::SafeString& tags) {
    sead::FixedSafeString<32> tag;
    for (auto it = tags.tokenBegin(","); tags.tokenEnd(",") != it; ++it) {
        it.get(&tag);
        if (hasTag(accessor, tag))
            return true;
    }
    return false;
}

// NON_MATCHING: this version doesn't have unnecessary register moves.
bool shouldSkipSpawnIfNotRaining(act::PreActor* obj) {
    if (obj->getFlags().isOff(act::PreActor::Flag::CreateNotRain))
        return false;

    if (!world::Manager::instance())
        return false;

    const auto pos = obj->getTranslate();
    return !world::Manager::instance()->isRaining(pos);
}

bool shouldSkipSpawnIfGodForestOff(act::PreActor* obj) {
    bool value = false;
    if (obj->getFlags().isOff(act::PreActor::Flag::UnderGodForestOff))
        return false;
    if (!gdt::Manager::instance()->getBool(sAnimalMasterAppearanceHandle, &value, true))
        return false;
    return value != 0;
}

bool shouldSkipSpawnGodForestActor(act::PreActor* obj) {
    bool value = false;
    if (obj->getFlags().isOn(act::PreActor::Flag::UnderGodForest) &&
        gdt::Manager::instance()->getBool(sAnimalMasterAppearanceHandle, &value, true) && !value) {
        return true;
    }
    return shouldSkipSpawnIfGodForestOff(obj);
}

static bool isFairyCountCheckEnabled() {
    bool value = false;
    return gdt::Manager::instance()->getBool(sFairyCountCheckHandle, &value, true) && value;
}

bool shouldSkipSpawnFairy(act::PreActor* obj) {
    const act::ActorData& actor_data = obj->getActorData();
    if (!actor_data.mFlags.isOnBit(act::ActorData::Flag::Fairy))
        return false;

    return isFairyCountCheckEnabled();
}

bool shouldSkipSpawnFairy(const sead::SafeString& actor) {
    auto* info = act::InfoData::instance();
    if (!info || !info->hasTag(actor.cstr(), act::tags::Fairy))
        return false;

    return isFairyCountCheckEnabled();
}

void initSpawnConditionGameDataFlags() {
    sFairyCountCheckHandle = gdt::Manager::instance()->getBoolHandle("FairyCountCheck");
    sAnimalMasterAppearanceHandle =
        gdt::Manager::instance()->getBoolHandle("AnimalMaster_Appearance");
    sIsGetStopTimerLv2Handle = gdt::Manager::instance()->getBoolHandle("IsGet_Obj_StopTimerLv2");
}

// TODO: remove this once IsGetStopTimerLv2 is used
// The only purpose of this function is to prevent sIsGetStopTimerLv2Handle from being optimized out
auto initSpawnConditionGameDataFlags_dummy() {
    return sIsGetStopTimerLv2Handle;
}

// NON_MATCHING: redundant branches in the original code.
bool hasAnyRevivalTag(const sead::SafeString& actor) {
    auto* info = act::InfoData::instance();
    al::ByamlIter iter;
    if (!info || !info->getActorIter(&iter, actor.cstr()))
        return false;

    for (auto tag : {
             act::tags::RevivalBloodyMoon,
             act::tags::RevivalRandom,
             act::tags::RevivalNone,
             act::tags::RevivalNoneForUsed,
             act::tags::RevivalRandomForDrop,
             act::tags::RevivalNoneForDrop,
             act::tags::RevivalUnderGodTime,
         }) {
        if (info->hasTag(iter, tag))
            return true;
    }
    return false;
}

bool hasStopTimerMiddleTag(act::Actor* actor) {
    return hasTag(actor, act::tags::StopTimerMiddle);
}

bool hasStopTimerShortTag(act::Actor* actor) {
    return hasTag(actor, act::tags::StopTimerShort);
}

// NON_MATCHING: ???
const char* arrowTypeToString(ArrowType idx) {
    return sArrowTypes[u32(idx)];
}

ArrowType arrowTypeFromString(const sead::SafeString& name) {
    for (s32 i = 0; i < sArrowTypes.size(); ++i) {
        if (name == sArrowTypes[i])
            return ArrowType(i);
    }
    return ArrowType::Invalid;
}

ZukanType getZukanType(al::ByamlIter* iter) {
    if (!iter)
        return ZukanType::Invalid;

    auto* info = act::InfoData::instance();

    if (info->hasTag(*iter, act::tags::ZukanAnimal))
        return ZukanType::Animal;

    if (info->hasTag(*iter, act::tags::ZukanEnemy))
        return ZukanType::Enemy;

    if (info->hasTag(*iter, act::tags::ZukanSozai))
        return ZukanType::Sozai;

    if (info->hasTag(*iter, act::tags::ZukanWeapon))
        return ZukanType::Weapon;

    if (info->hasTag(*iter, act::tags::ZukanOther))
        return ZukanType::Other;

    return ZukanType::Invalid;
}

ZukanType getZukanType(act::Actor* actor) {
    if (!actor)
        return ZukanType::Invalid;

    if (hasTag(actor, act::tags::ZukanAnimal))
        return ZukanType::Animal;

    if (hasTag(actor, act::tags::ZukanEnemy))
        return ZukanType::Enemy;

    if (hasTag(actor, act::tags::ZukanSozai))
        return ZukanType::Sozai;

    if (hasTag(actor, act::tags::ZukanWeapon))
        return ZukanType::Weapon;

    if (hasTag(actor, act::tags::ZukanOther))
        return ZukanType::Other;

    return ZukanType::Invalid;
}

static bool isProfile(const act::ActorLinkConstDataAccess& accessor,
                      const sead::SafeString& profile) {
    return accessor.hasProc() && accessor.getProfile() == profile;
}

bool isPlayerProfile(const act::ActorLinkConstDataAccess& accessor) {
    return isProfile(accessor, "Player");
}

bool isPlayerProfile(act::Actor* actor) {
    return isPlayerProfile(getAccessor(actor));
}

bool isPlayerProfile(frm::BaseProcLink* link) {
    return isPlayerProfile(getAccessor(link));
}

const sead::SafeString& getDefaultDropActor() {
    return sDefaultDropActor;
}

bool isCameraProfile(act::Actor* actor) {
    return isProfile(getAccessor(actor), "Camera");
}

bool isNPCProfile(const act::ActorLinkConstDataAccess& accessor) {
    return isProfile(accessor, "NPC");
}

bool isNPCProfile(act::Actor* actor) {
    return isNPCProfile(getAccessor(actor));
}

bool isNPCProfile(frm::BaseProcLink* link) {
    return isNPCProfile(getAccessor(link));
}

bool isNPCOffPodFromWeapon(act::Actor* actor) {
    if (!actor)
        return false;

    auto* gparam = actor->getParam()->getRes().mGParamList;
    if (!gparam)
        return false;

    const auto* npc_param = gparam->getNpc();
    return npc_param && npc_param->mIsOffPodFromWeapon.ref();
}

bool isDemoNPCProfile(act::Actor* actor) {
    return isProfile(getAccessor(actor), "DemoNPC");
}

bool isEnemyProfile(const act::ActorLinkConstDataAccess& accessor) {
    if (!accessor.hasProc())
        return false;

    const auto& profile = accessor.getProfile();

    return profile == "Enemy" || profile == "GiantEnemy" || profile == "Guardian" ||
           profile == "GuardianComponent" || profile == "LastBoss" || profile == "GelEnemy" ||
           profile == "EnemySwarm" || profile == "SiteBoss" || profile == "Sandworm" ||
           profile == "Dragon";
}

bool isEnemyProfile(act::Actor* actor) {
    return isEnemyProfile(getAccessor(actor));
}

bool isEnemyProfile(frm::BaseProcLink* link) {
    return isEnemyProfile(getAccessor(link));
}

bool isGuardianProfile(frm::BaseProcLink* link) {
    const auto accessor = getAccessor(link);
    if (!accessor.hasProc())
        return false;

    const auto& profile = accessor.getProfile();
    return profile == "Guardian" || profile == "GuardianComponent";
}

bool isLargeEnemy(const act::ActorLinkConstDataAccess& accessor) {
    if (!accessor.hasProc())
        return false;

    const auto& profile = accessor.getProfile();
    return profile == "GiantEnemy" || profile == "LastBoss" || profile == "SiteBoss" ||
           profile == "Sandworm" || profile == "Dragon";
}

bool isLargeEnemy(act::Actor* actor) {
    return isLargeEnemy(getAccessor(actor));
}

bool isGanonBeast(const act::ActorLinkConstDataAccess& accessor) {
    return accessor.hasProc() && accessor.getName() == "Enemy_GanonBeast";
}

bool isGanonBeast(frm::BaseProcLink* link) {
    return isGanonBeast(getAccessor(link));
}

bool isNotLivingCreature(act::Actor* actor) {
    return isNotLivingCreature(getAccessor(actor));
}

bool isNotLivingCreature(const act::ActorLinkConstDataAccess& accessor) {
    if (isPlayerProfile(accessor))
        return false;
    if (isNPCProfile(accessor))
        return false;
    if (isEnemyProfile(accessor))
        return false;
    if (isHorseProfile(accessor))
        return false;
    if (isPreyOrSwarm(accessor))
        return false;
    return true;
}

bool isNotLivingCreature(frm::BaseProcLink* link) {
    return isNotLivingCreature(getAccessor(link));
}

bool isWeaponProfile(const act::ActorLinkConstDataAccess& accessor) {
    if (!accessor.hasProc())
        return false;
    return isWeaponProfile(accessor.getName());
}

bool isWeaponProfile(const sead::SafeString& actor) {
    const char* profile = nullptr;
    act::InfoData::instance()->getActorProfile(&profile, actor.cstr());
    return sead::SafeString(profile).startsWith("Weapon");
}

bool isWeaponProfile(act::Actor* actor) {
    return isWeaponProfile(getAccessor(actor));
}

bool isWeaponProfile(frm::BaseProcLink* link) {
    return isWeaponProfile(getAccessor(link));
}

bool isWeaponOrArmor(const act::ActorLinkConstDataAccess& accessor) {
    if (!accessor.hasProc())
        return false;

    const auto& name = accessor.getName();
    const char* profile_cstr = nullptr;
    act::InfoData::instance()->getActorProfile(&profile_cstr, name.cstr());

    const sead::SafeString profile = profile_cstr;
    return profile.startsWith("Weapon") || profile.startsWith("OptionalWeapon") ||
           profile.startsWith("Armor");
}

bool isWeaponOrArmor(act::Actor* actor) {
    return isWeaponOrArmor(getAccessor(actor));
}

bool isBulletProfile(const act::ActorLinkConstDataAccess& accessor) {
    return isProfile(accessor, "Bullet");
}

bool isBulletProfile(act::Actor* actor) {
    return isBulletProfile(getAccessor(actor));
}

bool isBulletProfile(frm::BaseProcLink* link) {
    return isBulletProfile(getAccessor(link));
}

bool isHorseProfile(const act::ActorLinkConstDataAccess& accessor) {
    return isProfile(accessor, "Horse");
}

bool isHorseProfile(act::Actor* actor) {
    return isHorseProfile(getAccessor(actor));
}

bool isHorseProfile(frm::BaseProcLink* link) {
    return isHorseProfile(getAccessor(link));
}

bool isGrabAttClientEnabled(void*, frm::BaseProcLink* link) {
    return getAccessor(link).isAttClientEnabled("Grab");
}

bool isStalfosParts(frm::BaseProcLink* link) {
    const auto accessor = getAccessor(link);
    return accessor.hasProc() && accessor.hasTag(act::tags::StalfosParts);
}

bool isDoor(const act::ActorLinkConstDataAccess& accessor) {
    return accessor.hasProc() && accessor.hasTag(act::tags::Door);
}

bool isDoor(frm::BaseProcLink* link) {
    return isDoor(getAccessor(link));
}

bool isPreyOrSwarm(const act::ActorLinkConstDataAccess& accessor) {
    if (!accessor.hasProc())
        return false;
    const auto& profile = accessor.getProfile();
    return profile == "Prey" || profile == "Swarm";
}

bool isPreyOrSwarm(act::Actor* actor) {
    return isPreyOrSwarm(getAccessor(actor));
}

bool isPreyOrSwarm(frm::BaseProcLink* link) {
    return isPreyOrSwarm(getAccessor(link));
}

bool isWolfOrBear(const act::ActorLinkConstDataAccess& accessor) {
    if (!accessor.hasProc())
        return false;
    return accessor.hasTag(act::tags::AnimalTypeWolf) || accessor.hasTag(act::tags::AnimalTypeBear);
}

bool isWolfOrBear(act::Actor* actor) {
    return isWolfOrBear(getAccessor(actor));
}

bool isWolfOrBear(frm::BaseProcLink* link) {
    return isWolfOrBear(getAccessor(link));
}

bool isRope(act::Actor* actor) {
    const auto accessor = getAccessor(actor);
    return accessor.hasProc() && accessor.isDerivedFrom<RopeBase>();
}

bool isRope(frm::BaseProcLink* link) {
    const auto accessor = getAccessor(link);
    return accessor.hasProc() && accessor.isDerivedFrom<RopeBase>();
}

bool isTreeOrScaffoldOrSignboard(act::Actor* actor) {
    const auto accessor = getAccessor(actor);
    if (!accessor.hasProc())
        return false;

    return accessor.hasTag(act::tags::Tree) || accessor.hasTag(act::tags::Scaffold) ||
           accessor.hasTag(act::tags::Signboard);
}

bool isAirOctaPlatform(const sead::SafeString& name) {
    return name == "Obj_BoardWood_Square_01" || name == "Obj_BoardWood_Triangle_01" ||
           name == "FldObj_DLC_FlyShield_A_Snow_01" || name == "FldObj_DLC_FlyShield_A_Snow_02";
}

bool isAirOctaWoodPlatformDlc(const sead::SafeString& name) {
    return name == "FldObj_DLC_FlyShield_Wood_A_02" ||
           name == "FldObj_DLC_FlyShield_Wood_A_Snow_02";
}

void getRevivalGridPosition(const sead::Vector3f& pos, int* col1, int* row1, int* col2, int* row2) {
    const int col = sead::Mathi::clamp((int(pos.x) + 5000) / 1000, 0, 9);
    const int row = sead::Mathi::clamp((int(pos.z) + 4000) / 1000, 0, 7);

    const auto x = (float(col) + 0.5f) * 1000.0f - 5000.0f;
    const auto z = (float(row) + 0.5f) * 1000.0f - 4000.0f;

    if (x < pos.x) {
        *col1 = col;
        *col2 = col + 1;
    } else {
        *col1 = col - 1;
        *col2 = col;
    }

    if (z < pos.z) {
        *row1 = row;
        *row2 = row + 1;
    } else {
        *row1 = row - 1;
        *row2 = row;
    }
}

bool getSameGroupActorName(sead::SafeString* name, frm::BaseProcLink* link) {
    return getAccessor(link).getSameGroupActorName(name);
}

bool getSameGroupActorName(sead::SafeString* name, act::Actor* actor) {
    return getAccessor(actor).getSameGroupActorName(name);
}

bool getSameGroupActorName(sead::SafeString* name, const sead::SafeString& default_value,
                           al::ByamlIter* actor_info) {
    const sead::SafeString value = act::InfoData::instance()->getSameGroupActorName(*actor_info);
    if (value.isEmpty()) {
        *name = default_value;
        return false;
    }
    *name = value;
    return true;
}

bool getSameGroupActorName(sead::SafeString* name, const sead::SafeString& actor_name) {
    const sead::SafeString value =
        act::InfoData::instance()->getSameGroupActorName(actor_name.cstr());
    if (value.isEmpty()) {
        *name = actor_name;
        return false;
    }
    *name = value;
    return true;
}

bool getRandomAreaItem(sead::SafeString* item, const AreaItemType& type,
                       const sead::Vector3f& pos) {
    auto* eco = Ecosystem::instance();
    if (!eco)
        return false;

    const int area = eco->getFieldMapArea(pos.x, pos.z);
    AreaItemSet items;
    eco->getAreaItems(area, type, &items);

    int chosen_idx = -1;
    int running_total = 0;

    for (int idx = 0; idx < items.count; ++idx) {
        const int num = items.items[idx].num;
        running_total += num;
        if (int(sead::GlobalRandom::instance()->getU32(running_total)) < num)
            chosen_idx = idx;
    }

    if (chosen_idx < 0) {
        *item = sead::SafeString::cEmptyString;
        return false;
    }

    *item = items.items[chosen_idx].name;
    return true;
}

bool isInSatoriMountainArea(const sead::Vector3f& pos) {
    return Ecosystem::instance()->getFieldMapArea(pos.x, pos.z) == 64;
}

}  // namespace ksys::game
