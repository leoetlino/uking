#pragma once

#include <math/seadMatrix.h>
#include <prim/seadSafeString.h>
#include "Game/gameItemUtils.h"

namespace sead {
class Heap;
}

namespace ksys::act {
class BaseProcHandle;
class InstParamPack;
}  // namespace ksys::act

namespace uking::ui {
class PouchItem;
}  // namespace uking::ui

namespace uking::act {

enum class CreateEquipmentSlot : u8;
struct WeaponModifierInfo;
void requestCreateWeaponByRawLife(const char* actor_class, const sead::Matrix34f& matrix, f32 scale,
                                  sead::Heap* heap, ksys::act::BaseProcHandle* handle, s32 life,
                                  bool is_player_put, const WeaponModifierInfo* modifier,
                                  s32 task_lane_id, s32 res_lane_id);

int getWeaponGeneralLife(const char* name);

bool isOneHitObliteratorActorName(const sead::SafeString& name);

void addItemForDebug(const sead::SafeString& name, int value);

// 710073c5b4
void spawnDroppedInventoryItem(const char* name, sead::Heap* heap, int life,
                               SleepAfterInit sleep_after_init,
                               const WeaponModifierInfo* weapon_modifiers,
                               SpawnViaCarryBox spawn_via_carry_box, float rotate_y,
                               float rotate_z);

}  // namespace uking::act
