#pragma once

#include <math/seadVector.h>
#include <prim/seadSafeString.h>

namespace al {
class ByamlIter;
}

namespace ksys::act {
class Actor;
class ActorLinkConstDataAccess;
class PreActor;
}  // namespace ksys::act

namespace ksys::frm {
class BaseProcLink;
}

namespace ksys::game {

enum class AreaItemType;

enum class ArrowType {
    /// Wooden arrows.
    Normal = 0,
    /// Bomb arrows.
    Bomb = 1,
    /// Ancient arrows.
    Ancient = 2,
    /// Fire arrows.
    Fire = 3,
    /// Ice arrows.
    Ice = 4,
    /// Shock arrows.
    Electric = 5,

    Invalid = -1,
};

/// Compendium type (図鑑 type).
enum class ZukanType {
    Animal = 0,
    Enemy = 1,
    /// Materials (素材).
    Sozai = 2,
    Weapon = 3,
    Other = 4,
    Invalid = 5,
};

bool hasTag(act::Actor* actor, const sead::SafeString& tag);
bool hasTag(frm::BaseProcLink* link, const sead::SafeString& tag);
bool hasTag(const act::ActorLinkConstDataAccess& accessor, const sead::SafeString& tag);
bool hasTag(const sead::SafeString& actor, const sead::SafeString& tag);

bool hasTag(act::Actor* actor, u32 tag);
bool hasTag(frm::BaseProcLink* link, u32 tag);
bool hasTag(const act::ActorLinkConstDataAccess& accessor, u32 tag);
bool hasTag(const sead::SafeString& actor, u32 tag);

/// Checks whether the actor has at least one of the specified tags.
/// @param tags A comma separated list of tags.
bool hasOneTagAtLeast(act::Actor* actor, const sead::SafeString& tags);
bool hasOneTagAtLeast(frm::BaseProcLink* link, const sead::SafeString& tags);
bool hasOneTagAtLeast(const act::ActorLinkConstDataAccess& accessor, const sead::SafeString& tags);

bool shouldSkipSpawnIfNotRaining(act::PreActor* obj);
bool shouldSkipSpawnIfGodForestOff(act::PreActor* obj);
bool shouldSkipSpawnGodForestActor(act::PreActor* obj);
bool shouldSkipSpawnFairy(act::PreActor* obj);
bool shouldSkipSpawnFairy(const sead::SafeString& actor);

/// Must be called before using any of the "should skip" functions above.
void initSpawnConditionGameDataFlags();

bool hasAnyRevivalTag(const sead::SafeString& actor);

bool hasStopTimerMiddleTag(act::Actor* actor);
bool hasStopTimerShortTag(act::Actor* actor);
bool canBeStasised(act::Actor* actor, bool force);

void highlightStasisableActors(bool on);

const char* arrowTypeToString(ArrowType idx);
ArrowType arrowTypeFromString(const sead::SafeString& name);

ZukanType getZukanType(al::ByamlIter* iter);
ZukanType getZukanType(act::Actor* actor);

bool isPlayerProfile(const act::ActorLinkConstDataAccess& accessor);
bool isPlayerProfile(act::Actor* actor);
bool isPlayerProfile(frm::BaseProcLink* link);

bool isCameraProfile(act::Actor* actor);

bool isNPCProfile(const act::ActorLinkConstDataAccess& accessor);
bool isNPCProfile(act::Actor* actor);
bool isNPCProfile(frm::BaseProcLink* link);
bool isNPCOffPodFromWeapon(act::Actor* actor);

bool isDemoNPCProfile(act::Actor* actor);

bool isEnemyProfile(const act::ActorLinkConstDataAccess& accessor);
bool isEnemyProfile(act::Actor* actor);
bool isEnemyProfile(frm::BaseProcLink* link);

bool isGuardianProfile(frm::BaseProcLink* link);

bool isLargeEnemy(const act::ActorLinkConstDataAccess& accessor);
bool isLargeEnemy(act::Actor* actor);

bool isGanonBeast(const act::ActorLinkConstDataAccess& accessor);
bool isGanonBeast(frm::BaseProcLink* link);

bool isNotLivingCreature(act::Actor* actor);
bool isNotLivingCreature(const act::ActorLinkConstDataAccess& accessor);
bool isNotLivingCreature(frm::BaseProcLink* link);

bool isWeaponProfile(const act::ActorLinkConstDataAccess& accessor);
bool isWeaponProfile(const sead::SafeString& actor);
bool isWeaponProfile(act::Actor* actor);
bool isWeaponProfile(frm::BaseProcLink* link);

bool isWeaponOrArmor(const act::ActorLinkConstDataAccess& accessor);
bool isWeaponOrArmor(act::Actor* actor);

bool isBulletProfile(const act::ActorLinkConstDataAccess& accessor);
bool isBulletProfile(act::Actor* actor);
bool isBulletProfile(frm::BaseProcLink* link);

bool isHorseProfile(const act::ActorLinkConstDataAccess& accessor);
bool isHorseProfile(act::Actor* actor);
bool isHorseProfile(frm::BaseProcLink* link);

bool isAttClientEnabled(act::Actor* actor, const sead::SafeString& client);
bool isGrabAttClientEnabled(void* x, frm::BaseProcLink* link);

bool isStalfosParts(frm::BaseProcLink* link);

bool isDoor(const act::ActorLinkConstDataAccess& accessor);
bool isDoor(frm::BaseProcLink* link);

bool isPreyOrSwarm(const act::ActorLinkConstDataAccess& accessor);
bool isPreyOrSwarm(act::Actor* actor);
bool isPreyOrSwarm(frm::BaseProcLink* link);

bool isWolfOrBear(const act::ActorLinkConstDataAccess& accessor);
bool isWolfOrBear(act::Actor* actor);
bool isWolfOrBear(frm::BaseProcLink* link);

bool isRope(act::Actor* actor);
bool isRope(frm::BaseProcLink* link);

bool isTreeOrScaffoldOrSignboard(act::Actor* actor);

bool isAlive(frm::BaseProcLink* link);

bool isAirOctaPlatform(const sead::SafeString& name);
bool isAirOctaWoodPlatformDlc(const sead::SafeString& name);

const sead::SafeString& getDefaultDropActor();

void getRevivalGridPosition(const sead::Vector3f& pos, int* col1, int* row1, int* col2, int* row2);

bool getSameGroupActorName(sead::SafeString* name, frm::BaseProcLink* link);
bool getSameGroupActorName(sead::SafeString* name, act::Actor* actor);
bool getSameGroupActorName(sead::SafeString* name, const sead::SafeString& default_value,
                           al::ByamlIter* actor_info);
bool getSameGroupActorName(sead::SafeString* name, const sead::SafeString& actor_name);

s32 getSelectedChoiceIdx(s32 max, const char* query_name);

bool getRandomAreaItem(sead::SafeString* item, const AreaItemType& type, const sead::Vector3f& pos);
bool isInSatoriMountainArea(const sead::Vector3f& pos);

}  // namespace ksys::game
