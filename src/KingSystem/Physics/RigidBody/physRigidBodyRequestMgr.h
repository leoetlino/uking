#pragma once

#include <basis/seadRawPrint.h>
#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>
#include <container/seadSafeArray.h>
#include <hostio/seadHostIONode.h>
#include <math/seadVector.h>
#include <prim/seadDelegate.h>
#include <thread/seadAtomic.h>
#include <thread/seadCriticalSection.h>
#include "KingSystem/Game/Physics/physDefines.h"
#include "KingSystem/Physics/RigidBody/physRigidBodyContactEvent.h"
#include "KingSystem/Physics/System/physLayerContactPointInfo.h"
#include "KingSystem/Utils/Container/LockFreeQueue.h"
#include "KingSystem/Utils/Types.h"

class hkpEntity;

namespace ksys::phys {

class Constraint;
class MotionAccessor;
class RigidBody;

struct WaterContactRequest {
    sead::Vector3f flow_velocity = sead::Vector3f::zero;
    u8 water_shape_type = 0;
    u8 water_kind = 0;
    u8 water_sub_material = 0;
    bool has_terrain_flow = true;
    sead::Vector3f contact_position = sead::Vector3f::zero;
    RigidBody* body{};
    sead::Vector3f contact_normal = sead::Vector3f::ey;
    float cylinder_radius{};
    sead::Vector3f buoyancy_center = sead::Vector3f::zero;
    float submerged_ratio{};
};
KSYS_CHECK_SIZE_NX150(WaterContactRequest, 0x48);

class RigidBodyRequestMgr : public sead::hostio::Node {
public:
    struct Config {
        float flow_axis_blend = 0.6;
        float flow_box_strength = 0.7;
        float tree_aabb_scale = 1.25;
        float submerged_volume_scale = 1.0;
        float tree_buoyancy_offset = 0.2;
        float buoyancy_center_com_blend = 0.9;
        float delta_time_change_compensation = 0.5;
        float rope_buoyancy_scale = 1.0;
        float flow_impulse_scale = 4.0;
        // 5000m/s (squared)
        float linear_velocity_threshold_sq = 2.5e7;

        static Config& get();
        static bool isLinearVelocityTooHigh(const sead::Vector3f& velocity);
        static void enableLinearVelocityChecks(bool enable);
    };

    RigidBodyRequestMgr();
    virtual ~RigidBodyRequestMgr();

    void init(sead::Heap* heap);

    // 0x0000007100fa6438
    void calc(ContactLayerType layer_type);
    void calc1(ContactLayerType layer_type, bool paused);

    bool pushRigidBody(ContactLayerType type, RigidBody* body);
    void addEntityToWorld(ContactLayerType type, hkpEntity* entity);
    void removeEntityFromWorld(ContactLayerType type, hkpEntity* entity);
    // 0x0000007100fa6ebc
    void removeRigidBody(ContactLayerType type, RigidBody* body);

    bool onMaxPositionExceeded(ContactLayerType layer_type, RigidBody* body);

    bool addImpulse(RigidBody* body_a, RigidBody* body_b, float impulse);

    bool registerMotionAccessor(MotionAccessor* accessor);
    bool deregisterMotionAccessor(MotionAccessor* accessor);

private:
    struct GravitySuspensionRequest {
        RigidBody* body;
        u8 num_elapsed_frames;
        u8 num_frames;
        float original_gravity_factor;
    };
    KSYS_CHECK_SIZE_NX150(GravitySuspensionRequest, 0x10);

    struct ImpulseEntry {
        RigidBody* body_a;
        RigidBody* body_b;
        float impulse_a;
    };
    KSYS_CHECK_SIZE_NX150(ImpulseEntry, 0x18);

    struct PointCallback : LayerContactPointInfo::ContactCallback {
        explicit PointCallback(RigidBodyRequestMgr* mgr_) : mgr(mgr_) {}

        bool invoke(const LayerContactPointInfo::ContactEvent& event) override {
            return mgr->markWaterContactFlags(event);
        }

        RigidBodyRequestMgr* mgr;
    };

    // FIXME: implement
    bool markWaterContactFlags(const LayerContactPointInfo::ContactEvent& event);
    static bool filterTriangleEdgeContact(const RigidBodyContactEvent& event);

    void processImpulseEntries();
    void processOobRigidBodyEntries(ContactLayerType layer_type);

    static constexpr int NumRigidBodyBuffers = 2;
    static constexpr int MaxNumImpulseEntries = 0x100;

    sead::SafeArray<util::LockFreeQueue<RigidBody>, NumRigidBodyBuffers> mPendingUpdateBodies;
    util::LockFreeQueue<Constraint> mConstraintRequests;
    util::LockFreeQueue<Constraint> mConstraintsToProcess;
    /// Rigid bodies that are out of bounds.
    sead::SafeArray<util::LockFreeQueue<RigidBody>, NumRigidBodyBuffers> mOobRigidBodies;
    util::LockFreeQueue<ImpulseEntry> mImpulseEntries;
    util::LockFreeQueue<WaterContactRequest> mWaterContactRequests;
    util::LockFreeQueue<GravitySuspensionRequest> mGravitySuspensionRequests;
    util::LockFreeQueue<GravitySuspensionRequest> mFreeGravitySuspensionRequests;
    sead::PtrArray<MotionAccessor> mMotionAccessors;
    sead::Buffer<ImpulseEntry> mImpulseEntriesPool;
    sead::Atomic<int> mNumActiveImpulseEntries;
    sead::Buffer<WaterContactRequest> mWaterContactRequestPool;
    sead::Atomic<u32> mNumWaterContactRequests;
    sead::Buffer<GravitySuspensionRequest> mGravitySuspensionRequestPool;
    u32 mNumEntitiesInWorld{};
    LayerContactPointInfo* mContactPoints{};
    sead::SafeArray<sead::CriticalSection, NumRigidBodyBuffers> mCriticalSections;
    sead::CriticalSection mCS;
    float mTimeFactor = 1.0;
    float mDeltaTime = 1.0 / 30.0;
    float mPrevDeltaTime = 1.0 / 30.0;
    float mScaledDeltaTime = 1.0 / 30.0;
    float mPrevScaledDeltaTime = 1.0 / 30.0;
    sead::Atomic<u32> _22c;
    u32 mWaterIceSubmatIdx{};
    u32 mWaterHotSubmatIdx{};
    u32 mWaterPoisonSubmatIdx{};
    PointCallback mCallback{this};
    sead::Delegate1RFunc<const RigidBodyContactEvent&, bool> mTriangleEdgeContactFilter{
        &RigidBodyRequestMgr::filterTriangleEdgeContact};
};
KSYS_CHECK_SIZE_NX150(RigidBodyRequestMgr, 0x260);

}  // namespace ksys::phys
