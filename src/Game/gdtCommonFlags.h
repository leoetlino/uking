#pragma once

#include <math/seadVector.h>
#include <prim/seadSafeString.h>
#include "KingSystem/GameData/gdtFlagUtils.h"
#include "KingSystem/GameData/gdtManager.h"

#include "Game/gdtCommonFlagsAccessorDecls.inc"
#include "Game/gdtCommonFlagsHandleDecls.inc"

namespace ksys::act {
class Actor;
}

namespace uking::flagname {

const char* AoC_HardMode_Enabled();
const char* BowPorchStockNum();
const char* CaptionPictSize();
const char* CurrentHart();
const char* CurrentMamo();
const char* CurrentRupee();
const char* CurrentTotalGetRupeeInMiniGame();
const char* DungeonClearSealNum();
const char* IsGet_Armor_014_Head();
const char* IsGet_Armor_014_Lower();
const char* IsGet_Armor_014_Upper();
const char* IsGet_Armor_046_Head();
const char* IsGet_Armor_046_Lower();
const char* IsGet_Armor_046_Upper();
const char* IsGet_Armor_048_Head();
const char* IsGet_Armor_048_Lower();
const char* IsGet_Armor_048_Upper();
const char* IsGet_Armor_083_Head();
const char* IsGet_Armor_083_Lower();
const char* IsGet_Armor_083_Upper();
const char* IsGet_Armor_084_Head();
const char* IsGet_Armor_084_Lower();
const char* IsGet_Armor_084_Upper();
const char* IsGet_Armor_085_Head();
const char* IsGet_Armor_085_Lower();
const char* IsGet_Armor_085_Upper();
const char* IsGet_Armor_086_Head();
const char* IsGet_Armor_086_Lower();
const char* IsGet_Armor_086_Upper();
const char* IsGet_Armor_103_Head();
const char* IsGet_Armor_103_Lower();
const char* IsGet_Armor_103_Upper();
const char* IsGet_Armor_104_Head();
const char* IsGet_Armor_104_Lower();
const char* IsGet_Armor_104_Upper();
const char* IsGet_Armor_105_Head();
const char* IsGet_Armor_105_Lower();
const char* IsGet_Armor_105_Upper();
const char* IsGet_Armor_106_Head();
const char* IsGet_Armor_106_Lower();
const char* IsGet_Armor_106_Upper();
const char* IsGet_Armor_111_Head();
const char* IsGet_Armor_111_Lower();
const char* IsGet_Armor_111_Upper();
const char* IsGet_Armor_112_Head();
const char* IsGet_Armor_112_Lower();
const char* IsGet_Armor_112_Upper();
const char* IsGet_Armor_113_Head();
const char* IsGet_Armor_113_Lower();
const char* IsGet_Armor_113_Upper();
const char* IsGet_Armor_114_Head();
const char* IsGet_Armor_114_Lower();
const char* IsGet_Armor_114_Upper();
const char* IsSaveByAuto();
const char* KorokNutsNum();
const char* LastSaveTime_Lower();
const char* LastSaveTime_Upper();
const char* SaveDistrictName();
const char* SaveLocationName();
const char* TrackBlockFileNumber();
const char* TrackBlockFileNumber_Hard();

}  // namespace uking::flagname

namespace uking {

bool isSaveProhibited();
bool isWarpProhibited();
bool isKillTimeProhibited();

s32 getSmallKeyNum(const sead::SafeString& map, bool debug = false);
s32 getDungeonNum(const sead::SafeString& map);
void incrementSmallKeyNum(const sead::SafeString& map, s32 value, bool debug = false);

s32 getS32ByKey(const sead::SafeString& flag, bool debug = false);
bool setS32ByKey(s32 value, const sead::SafeString& flag, bool debug = false);

bool setBoolByKey(bool value, const sead::SafeString& flag, bool debug = false);
bool getBoolByKey(const sead::SafeString& flag, bool debug = false);

bool isDungeonCleared(const sead::SafeString& map, bool debug = false);
void setDungeonCleared(const sead::SafeString& map, bool cleared, bool debug = false);

bool isDungeonEntered(const sead::SafeString& map, bool debug = false);
void setDungeonEntered(const sead::SafeString& map, bool entered, bool debug = false);

bool isGetItem(const sead::SafeString& actor, bool debug = false);
bool isGetItem(ksys::act::Actor* actor, bool debug = false);
void setIsGetItem(const sead::SafeString& actor, bool value, bool debug = false);
// XXX: Same as isGetItem -- why does this exist?
bool isGetItem2(const sead::SafeString& actor, bool debug = false);
void setIsGetItem2(const sead::SafeString& actor, bool value, bool debug = false);

f32 getF32ByKey(const sead::SafeString& flag, bool debug = false);
void getStr64ByKey(const char** value, const sead::SafeString& flag, bool debug = false);
void getVec3fByKey(sead::Vector3f* value, const sead::SafeString& flag, bool debug = false);
s32 getS32ByKey(const sead::SafeString& flag, s32 sub_idx, bool debug = false);
f32 getF32ByKey(const sead::SafeString& flag, s32 sub_idx, bool debug = false);
void getStr64ByKey(const char** value, const sead::SafeString& flag, s32 sub_idx,
                   bool debug = false);
bool setF32ByKey(f32 value, const sead::SafeString& flag, bool debug = false);
bool setStr64ByKey(const sead::SafeString& value, const sead::SafeString& flag, bool debug = false);

}  // namespace uking
