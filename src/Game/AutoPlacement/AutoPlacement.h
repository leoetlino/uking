#pragma once

#include <math/seadVector.h>
#include <prim/seadDelegate.h>
#include <prim/seadSafeString.h>
#include <prim/seadTypedBitFlag.h>
#include <thread/seadCriticalSection.h>
#include "KingSystem/Game/Physics/physMaterialMask.h"
#include "KingSystem/Map/mapObjectLink.h"
#include "KingSystem/Map/mapPreActor.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::phys {
class RayCastForRequest;
class RigidBody;
}  // namespace ksys::phys

namespace uking {

class AutoPlacement;
struct AutoPlacementFlowRes;
class PlacementThing;

struct PlacementGroup {
    sead::SafeString actor_name;
    u32 group_radius;
    u32 offset_pos_y;
    u8 grid_x;
    u8 grid_z;
    u8 num;
    u8 equip_weapon_actor_count;
    u8 flow_idx;
    u8 locator_type;
    u8 is_active;
    u8 flags{};
    s16 object_ref_idx;
    u16 weather_mask{};
    u8 num_killed;
    u8 time_division_mask{};
    void* _28;
    void* _30;
    void* _38;
    void* _40;
    void* _48;
    void* _50;
    void* _58;
    void* _60;
    void* _68;
    sead::SafeString b;
    u32 num_alive{};
};
KSYS_CHECK_SIZE_NX150(PlacementGroup, 0x88);

class PlacementThing {
public:
    enum class State : u32 {
        Invalid,
        Uninitialized,
        Initialized,
        LayersDone,
        RaycastDone,
        PlacementDone,
    };

    explicit PlacementThing(bool is_obstacle_sweep)
        : mDelegate{this, &PlacementThing::onRayHitRigidBody}, mIsObstacleSweep(is_obstacle_sweep) {
    }

    bool invoke();
    void stepRaycast();
    void onRayHitRigidBody(ksys::phys::RigidBody*);
    const char* getCurrentGroundMat() const;
    const char* getCurrentWaterSubMat() const;

private:
    friend class AutoPlacement;

    ksys::phys::RayCastForRequest* mRaycast{};
    u8 mHit{};
    u8 mUnderwater{};
    sead::Vector3f mStartPos{};
    sead::Vector3f mQueryVec{};
    u32 _889c{};
    f32 _88a0 = 1.0f;
    ksys::phys::MaterialMask mGroundMaterial;
    ksys::phys::MaterialMask mWaterMaterial;
    f32 mWaterQuery = -1.0f;
    sead::Delegate1<PlacementThing, ksys::phys::RigidBody*> mDelegate;
    sead::CriticalSection mCS{};
    State mState;
    u8 mIsObstacleSweep{};
    u8 mSweepRayCount{};
};

struct ActorSpawnInfo {
    enum class SpawnLocation : u16 {
        CheckBirdSafetyArea = 1,

        // exclusive
        TrunkOrGlowStoneLocator = 2,
        TrunkLocator = 4,
        TrunkLocatorRandom = 8,
        BranchLocator = 0x10,
        BranchLocatorRandom = 0x20,
        OnTreeLocator = 0x40,
        OnTreeLocatorRandom = 0x80,

        IsSnowBall = 0x100,
    };

    void calcSpawnLocations();

    sead::SafeString name{};
    AutoPlacementFlowRes* flow;
    u8 max_groups;
    u8 num_groups_placed;
    sead::TypedBitFlag<SpawnLocation> spawn_location{};
    u16 max_attempts;
    u16 num_attempts;
};

class AutoPlacement {
public:
    AutoPlacement();
    ~AutoPlacement();

    enum class State : u8 {
        Ready,
        NeedsLocators,
        Inactive,
    };

    bool init(sead::Heap* heap, u8 flag, s32 num_spawn, s32 num_obj);
    u32 isWithinOneCellOf(u32, u32);
    void reset(bool force);

    bool hasNearbyPlacedActorWithNameInGroup(const sead::SafeString& name,
                                             const sead::Vector3f& distance);

    void setSpawnInfo(const sead::SafeString& name, s32 count);
    void deactivate();

    bool isActorInEcosystemAreaAtPos(const sead::SafeString& name, u32 placement_type,
                                     const sead::Vector3f& pos);
    bool canSpawnEntryAtPos(ActorSpawnInfo* info, const sead::Vector3f& pos);
    void updateCurrentGroupNum(u8 num, u8 equip_weapon_actor_count);
    void incrementGroup();
    bool isGroupLocatorUnavailable(PlacementGroup* grp, bool check_exposure);
    s32 placeGroup(AutoPlacementFlowRes* res);
    s32 getCurrentGroupFlowIdx();
    void stepAllRaycasts();
    void onRayHitRigidBody(ksys::phys::RigidBody* rb);

private:
    struct ObjectRef {
        ksys::map::PreActor* obj;
        void* locator_cache_idx;
    };

    s16 mNumGroups = 0;
    s16 mGroupIdx = -1;
    u8 mGridX = 0xFF;
    u8 mGridZ = 0xFF;
    s16 mNearCreateWaitFrame = 0;
    State mState = State::Ready;
    u8 mCurrentGroupMatched = 2;
    sead::BitFlag<u8> mNearFlag{};
    sead::BitFlag<u8> mEquipCategory{};
    u8 mCurSpawnInfoIdx = 0;
    u8 mNumSpawnInfos = 0;
    u8 mAppearWeatherMask = 0;
    u8 _f = 0;
    u8 mTimeDivisionMask = 0;
    s32 mResetCount = 0;
    sead::Buffer<ActorSpawnInfo> mSpawnInfo;
    sead::CriticalSection mCS{};
    sead::SafeArray<PlacementGroup, 0x100> mGroups{};
    sead::SafeString mRailName{};
    PlacementThing mCandidateRay{false};
    PlacementThing mSpawnRay{false};
    PlacementThing mObstacleRay{true};
    void* mCurRay;
    sead::Buffer<ObjectRef> mObjectRefs;
};

}  // namespace uking
