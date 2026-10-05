#pragma once

#include <basis/seadTypes.h>
#include <container/seadPtrArray.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>
#include <thread/seadCriticalSection.h>
#include <thread/seadMutex.h>
#include "KingSystem/Game/Physics/physDefines.h"
#include "KingSystem/System/DebugMessage.h"
#include "KingSystem/Utils/Types.h"

class hkFreeListAllocator;
class hkMemorySystem;
class hkProcess;
class hkpPhysicsContext;
class hkpWorld;

namespace ksys::phys {

class CharacterController;
class CollisionInfo;
class ContactLayerCollisionInfo;
class ContactLayerCollisionInfoGroup;
class ContactListener;
class ContactMgr;
class ContactPointInfo;
class GroupFilter;
class HavokMemoryAllocator;
class LayerContactPointInfo;
class MaterialTable;
class Phantom;
class RayCastForRequest;
class RayCastRequestMgr;
class RagdollControllerKeyList;
class RagdollInstanceMgr;
class RigidBody;
class RigidBodyRequestMgr;
class StaticCompoundMgr;
class SystemData;
class SystemGroupHandler;
class World;
struct HkThreadMemorySlot;

enum class IsIndoorStage {
    No,
    Yes,
};

enum class LowPriority : bool { Yes = true, No = false };
enum class OnlyLockIfNeeded : bool { Yes = true, No = false };

class System {
    SEAD_SINGLETON_DISPOSER(System)
    System();
    virtual ~System();

public:
    float getDeltaTime() const { return mDeltaTime; }
    float getDivisorRatio() const { return mDivisorRatio; }
    float getTimeFactor() const { return mTimeFactor; }
    ContactMgr* getContactMgr() const { return mContactMgr; }
    StaticCompoundMgr* getStaticCompoundMgr() const { return mStaticCompoundMgr; }
    RigidBodyRequestMgr* getRigidBodyRequestMgr() const { return mRigidBodyRequestMgr; }
    RagdollInstanceMgr* getRagdollInstanceMgr() const { return mRagdollInstanceMgr; }
    SystemData* getSystemData() const { return mSystemData; }
    MaterialTable* getMaterialTable() const { return mMaterialTable; }

    bool isPaused() const;

    void initSystemData(sead::Heap* heap);

    ContactPointInfo* allocContactPointInfo(sead::Heap* heap, int num, const sead::SafeString& name,
                                            int overflow_mode, int ignore_separated_points,
                                            int ignore_disabled_contacts) const;
    void freeContactPointInfo(ContactPointInfo* info) const;

    LayerContactPointInfo* allocLayerContactPointInfo(sead::Heap* heap, int num, int num2,
                                                      const sead::SafeString& name,
                                                      int overflow_mode,
                                                      int ignore_separated_points,
                                                      int ignore_disabled_contacts) const;
    void freeLayerContactPointInfo(LayerContactPointInfo* info) const;

    void registerContactPointInfo(ContactPointInfo* info) const;
    // 0x000000710121696c
    void registerCollisionInfo(CollisionInfo* info) const;
    // 0x0000007101216974
    void registerContactPointLayerPair(LayerContactPointInfo* info, ContactLayer layer1,
                                       ContactLayer layer2, bool do_not_delay_callback);

    // 0x00000071012169a4
    CollisionInfo* allocCollisionInfo(sead::Heap* heap, const sead::SafeString& name) const;
    // 0x00000071012169ac
    void freeCollisionInfo(CollisionInfo* info) const;

    // 0x00000071012169b4
    ContactLayerCollisionInfoGroup*
    makeContactLayerCollisionInfoGroup(sead::Heap* heap, ContactLayer layer, int capacity,
                                       const sead::SafeString& name);
    // 0x00000071012169c0
    void freeContactLayerCollisionInfoGroup(ContactLayerCollisionInfoGroup* group);
    // 0x00000071012169c8
    ContactLayerCollisionInfo* trackLayerPair(ContactLayer layer_a, ContactLayer layer_b);

    // 0x0000007101216a20
    void removeRigidBodyFromContactSystem(RigidBody* body);

    // 0x000000710121686c
    SystemGroupHandler* addSystemGroupHandler(ContactLayerType layer_type, int free_list_idx = 0);
    // 0x0000007101215b68
    void removeSystemGroupHandler(SystemGroupHandler* handler);

    hkpWorld* getHavokWorld(ContactLayerType type) const;

    // 0x0000007101215754
    void lockWorld(ContactLayerType type, const char* description = nullptr, int b = 0,
                   OnlyLockIfNeeded only_lock_if_needed = OnlyLockIfNeeded::No);
    // 0x0000007101215784
    void unlockWorld(ContactLayerType type, const char* description = nullptr, int b = 0,
                     OnlyLockIfNeeded only_lock_if_needed = OnlyLockIfNeeded::No);

    // 0x0000007101216ac8
    GroupFilter* getGroupFilter(ContactLayerType type) const;

    // 0x0000007101216ae8
    RayCastForRequest* allocRayCastRequest(SystemGroupHandler* group_handler = nullptr,
                                           GroundHit ground_hit = GroundHit::HitAll);

    RagdollControllerKeyList* getRagdollCtrlKeyList() const;

    // 0x0000007101216c60
    void setMagneMassScalingActive(bool value);
    // 0x0000007101216c74
    bool isMagneMassScalingActive() const;

    // 0x0000007101216ca4
    bool canModifyWorldDirectly() const;

    // 0x0000007101216800
    void setIgnoreObjectAndNpcContacts(bool value);
    // 0x0000007101216814
    bool isIgnoringObjectAndNpcContacts() const;

    // 0x000000710121682c
    void incrementWorldQueryRefCount(ContactLayerType layer_type);
    // 0x000000710121684c
    void decrementWorldQueryRefCount(ContactLayerType layer_type);

    bool isHavokMainHeapOom() const;

    sead::Heap* getPhysicsTempHeap(LowPriority low_priority) const;

private:
    sead::FixedPtrArray<World, 2> mWorlds;
    sead::Vector3f mGravity;
    sead::Vector3f mGravityDirection;
    bool mPaused;
    bool mStepSuspended;
    bool mIsCalculatingRigidBodyRequests;
    float mDeltaTime = 1.0 / 30.0;
    float mStepDeltaTime = 1.0 / 30.0;
    float mDivisorRatio = 1.0;
    float mSmoothedDeltaTime = 1.0 / 30.0;
    float mTimeFactor{};
    HavokMemoryAllocator* mHavokAllocator{};
    hkFreeListAllocator* mFreeListAllocator{};
    u8 _88[0x98 - 0x88];
    sead::PtrArray<HkThreadMemorySlot> mThreadMemorySlots;
    sead::CriticalSection mCS;
    hkMemorySystem* mHkMemorySystem{};
    hkProcess* mDebugDisplayProcess{};
    GroupFilter* mEntityGroupFilter{};
    GroupFilter* mSensorGroupFilter{};
    sead::FixedPtrArray<GroupFilter, 2> mGroupFilters;
    sead::FixedPtrArray<ContactListener, 2> mContactListeners;
    ContactMgr* mContactMgr;
    void* mPhysSourceListenerMgr;
    StaticCompoundMgr* mStaticCompoundMgr;
    RigidBodyRequestMgr* mRigidBodyRequestMgr;
    RagdollInstanceMgr* mRagdollInstanceMgr;
    void* mRigidBodyDividedMeshShapeMgr;
    SystemData* mSystemData;
    MaterialTable* mMaterialTable;
    RayCastRequestMgr* mRayCastRequestMgr{};
    RigidBody* mSystemDummyBody{};
    void* _198{};
    Phantom* mWorldBorderPhantom{};
    sead::Heap* mPhysicsSystemHeap{};
    sead::Heap* mDebugHeap{};
    sead::Heap* mPhysicsTempDefaultHeap{};
    sead::Heap* mPhysicsTempLowHeap{};
    DebugMessage mDebugMessage;
    u8 _258[0x268 - 0x258];
    IsIndoorStage mIsIndoorStage;
    sead::Mutex mCharacterControllerMutex;
    sead::PtrArray<CharacterController> mCharacterControllers;
    SystemGroupHandler* mSystemGroupHandlers[2][4];
    SystemGroupHandler* mLowIndexSystemGroupHandlers[2][2];
    u8 _320[0x328 - 0x320];
    hkpPhysicsContext* mPhysicsContext;
    u8 _330[0x448 - 0x330];
    int mPerCoreMaxCounters[3];
    void* mPerCoreScratchBuffers[3];
    u8 _470[0x480 - 0x470];
};
KSYS_CHECK_SIZE_NX150(System, 0x480);

class ScopedWorldLock {
public:
    explicit ScopedWorldLock(ContactLayerType type, const char* description = nullptr, int unk = 0,
                             OnlyLockIfNeeded only_lock_if_needed = OnlyLockIfNeeded::No)
        : ScopedWorldLock(true, type, description, unk, only_lock_if_needed) {}

    ScopedWorldLock(bool condition, ContactLayerType type, const char* description = nullptr,
                    int unk = 0, OnlyLockIfNeeded only_lock_if_needed = OnlyLockIfNeeded::No)
        : mCondition(condition), mType(type), mDescription(description), mUnk(unk),
          mOnlyLockIfNeeded(only_lock_if_needed) {
        if (mCondition)
            System::instance()->lockWorld(mType, mDescription, mUnk, mOnlyLockIfNeeded);
    }

    ~ScopedWorldLock() {
        if (mCondition)
            System::instance()->unlockWorld(mType, mDescription, mUnk, mOnlyLockIfNeeded);
    }

    ScopedWorldLock(const ScopedWorldLock&) = delete;
    auto operator=(const ScopedWorldLock&) = delete;

private:
    bool mCondition;
    ContactLayerType mType;
    const char* mDescription;
    int mUnk;
    OnlyLockIfNeeded mOnlyLockIfNeeded;
};

}  // namespace ksys::phys
