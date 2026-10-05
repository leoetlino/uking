#pragma once

#include <container/seadBuffer.h>
#include <container/seadListImpl.h>
#include <container/seadObjArray.h>
#include <container/seadPtrArray.h>
#include <gsys/gsysModelAccessKey.h>
#include <hostio/seadHostIONode.h>
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/Physics/RigidBody/physRigidBody.h"
#include "KingSystem/Physics/RigidBody/physRigidBodyParam.h"

namespace gsys {
class Model;
}

namespace sead {
class DirectResource;
}

namespace ksys::res {
class Handle;
class RagdollBlendWeight;
class RagdollConfigList;
}  // namespace ksys::res

namespace ksys::phys {

class CharacterController;
class CharacterFormSet;
class ClothSet;
class CollisionInfo;
class Constraint;
class ContactPointInfo;
class ModelBoneAccessor;
class NavMeshCharacter;
class NavMeshObj;
class ParamSet;
class RagdollController;
class RagdollInstance;
class RigidBodySet;
class SupportBoneWork;
class SystemGroupHandler;
class UserTag;

class InstanceSet : public sead::hostio::Node {
public:
    enum class Flag : u32 {
        Active = 1 << 0,
        TransformResetRequested = 1 << 1,
        ClothResetRequested = 1 << 2,
        TransformResetThisFrame = 1 << 3,
        ClothResetThisFrame = 1 << 4,
        SkipCopyHavokPoseToModel = 1 << 5,
        OwnsModelBoneAccessor = 1 << 6,
        IsMapConst = 1 << 7,
        MapConstPassive = 1 << 8,
        MapConstActive = 1 << 9,
        ViewerConstPassive = 1 << 10,
        DiscardVelocitiesOnFix = 1 << 11,
        ClothEnabled = 1 << 13,
        ClothBoneUpdateFailed = 1 << 14,
        ClothDisabled = 1 << 15,
        ClothDisabledWithReset = 1 << 16,
        ClothFrozen = 1 << 17,
        Fixed = 1 << 18,
        SupportBonesDisabled = 1 << 19,
        SupportBonesSuspendedByLod = 1 << 20,
        SupportBonesActive = 1 << 21,
        ClothResetIfMoved = 1 << 22,
        ClothResetCancelled = 1 << 23,
        ClothTeleportInsteadOfReset = 1 << 24,
        InDemo = 1 << 25,
        RagdollFrozen = 1 << 30,
        PoseSyncedThisFrame = 1u << 31,
    };

    enum class Flag2 : u32 {
        AllowMapConstPassiveInit = 1 << 20,
        ForceInactiveAndFixed = 1 << 21,
        ClothForceEnabled = 1 << 23,
        ClothForceDisabled = 1 << 24,
        SupportBonesIgnoreLod = 1 << 25,
        DebugDrawRagdollControllerWeights = 1 << 27,
    };

    InstanceSet(const sead::SafeString& actor_name, const sead::SafeString& actor_profile,
                const ParamSet& param_set);
    virtual ~InstanceSet();

    const sead::SafeString& getName() const { return mName; }
    const ParamSet* getParamSet() const { return mParamSet; }
    CharacterController* getCharacterController() const { return mCharacterController; }

    void requestTransformReset();
    void requestClothReset();
    void setInDemo();
    void resetInDemo();
    void setClothResetMode(s32 mode);
    void copyClothResetModeFrom(InstanceSet* other);
    u32 getClothResetMode() const;
    void addToWorld();
    void disableContactLayer(ContactLayer layer);
    void setContactNone();
    RigidBody* getRigidBody(s32 rigid_body_set_idx, s32 rigid_body_idx) const;
    void resetBodyContactSettingsFromParam(RigidBody* body, RigidBodyParam* param);
    void setMtxAndScale(const sead::Matrix34f& mtx, bool a2, bool a3, f32 scale);
    bool hasRagdollContactPoints() const;
    void* findX(const sead::SafeString& a1, const sead::SafeString& a2) const;
    RigidBody* findRigidBody(const sead::SafeString& name) const;
    s32 findContactPointInfo(const sead::SafeString& name) const;
    s32 findCollisionInfo(const sead::SafeString& name) const;
    void updateBodiesFromModelMatrix(const sead::Matrix34f& mtx);
    void updateBoneLinkedBodyTransforms(const sead::Matrix34f& mtx, bool is_sensor,
                                        bool set_immediately);
    s32 findRagdollControllerIdx(const sead::SafeString& name) const;

private:
    struct BodyBoneLink {
        gsys::BoneAccessKeyEx key;
        RigidBody* body;
        int mode;
        bool force_link;
        bool link_disabled_by_constraint;
    };
    KSYS_CHECK_SIZE_NX150(BodyBoneLink, 0x48);

    sead::SafeString mName;
    const ParamSet* mParamSet;
    sead::TypedBitFlag<Flag> mFlags;
    sead::TypedBitFlag<Flag2> mFlags2;
    gsys::Model* mModel;
    f32 mScale;
    UserTag* mUserTag;
    sead::PtrArray<RigidBodySet> mRigidBodySets;
    sead::PtrArray<CollisionInfo> mCollisionInfo;
    sead::PtrArray<ContactPointInfo> mContactPointInfo;
    sead::Buffer<res::Handle*> mRigidBodySetResHandles;

    CharacterController* mCharacterController{};
    CharacterFormSet* mCharacterFormSet{};

    RagdollInstance* mRagdollInstance{};
    sead::Buffer<RagdollController*> mRagdollControllers;
    ContactPointInfo* mRagdollContactPointInfo{};
    res::Handle* mRagdollResHandle{};
    res::RagdollBlendWeight* mRagdollBlendWt;
    res::RagdollConfigList* mRagdollConfigList;

    res::Handle* mClothResHandle{};
    sead::DirectResource* mClothRes{};
    ClothSet* mClothSet;

    res::Handle* mSupportBoneResHandle{};
    SupportBoneWork* mSupportBoneWork{};
    ModelBoneAccessor* mModelBoneAccessor{};

    NavMeshCharacter* mNavMeshCharacter;
    sead::Buffer<NavMeshObj> mNavMeshObjs;
    u16 mNavMeshObjId{};
    u8 mCurrentRagdollControllerIdx;
    sead::ObjArray<BodyBoneLink> mBodyBoneLinks;
    sead::Buffer<void*> mBodyBoneLinksPerModelUnit;
    sead::TList<RigidBody*> mExtraRigidBodies;
    sead::TList<Constraint*> mBoneConstraints;
    SystemGroupHandler* mOwnedSystemGroupHandlers[2];
    SystemGroupHandler* mSystemGroupHandlers[2];
};
KSYS_CHECK_SIZE_NX150(InstanceSet, 0x198);

}  // namespace ksys::phys
