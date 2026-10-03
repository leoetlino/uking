#pragma once

#include <container/seadBuffer.h>
#include <container/seadListImpl.h>
#include <gsys/gsysModelAccessKey.h>
#include <math/seadBoundBox.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>
#include <prim/seadTypedBitFlag.h>
#include <thread/seadAtomic.h>
#include <xlink2/xlink2Handle.h>
#include "KingSystem/ActorSystem/actActorEditorNode.h"
#include "KingSystem/ActorSystem/actBaseProc.h"
#include "KingSystem/ActorSystem/actBaseProcJobHandler.h"
#include "KingSystem/ActorSystem/actBaseProcLink.h"
#include "KingSystem/ActorSystem/actPhysicsConstraints.h"
#include "KingSystem/ActorSystem/actPhysicsUserTag.h"
#include "KingSystem/Map/mapMubinIter.h"
#include "KingSystem/Utils/AtomicLongBitFlag.h"
#include "KingSystem/Utils/Thread/ActorMessageTransceiver.h"

namespace gsys {
class Model;
}  // namespace gsys

namespace ksys {

namespace as {
class ASList;
}  // namespace as

namespace chm {
class ObjectSet;
}  // namespace chm

namespace map {
class PreActor;
}  // namespace map

namespace mii {
class HylianInfo;
class UMii;
}  // namespace mii

namespace phys {
class StaticCompoundRigidBodyGroup;
class InstanceSet;
class RigidBody;
class CharacterController;
}  // namespace phys

namespace reaction {
class ActorReactions;
}  // namespace reaction

namespace res {
class Handle;
class ModelResourceTextureCache;
class ModelTextureBinding;
}  // namespace res

namespace xlink {
class ActorEffects;
}  // namespace xlink

namespace act {

namespace ai {
class RootAi;
}

class LifeRecoverInfo;
class Actor;
class ActorCreator;
class ActorParam;
class Attention;
class AwarenessInstance;
class BaseProcLink;
class BoneControl;
class Chemical;
class ImpulseBaseProcLink;
class IncomingDamageHandler;
class LodState;
class ModelBindInfo;
class Schedule;

// FIXME: move this to a separate file and rename
class UMiiModelLink {
public:
    explicit UMiiModelLink(Actor* actor) : mActor(actor) {}

    virtual void m0() {}
    virtual void m1() {}
    virtual void m2() {}
    virtual void m3() {}

private:
    Actor* mActor = nullptr;
};
KSYS_CHECK_SIZE_NX150(UMiiModelLink, 0x10);

struct ActorUniqueName {
    sead::BufferedSafeString* unique_name;
    sead::FixedSafeString<16> change_attention_type;
};
KSYS_CHECK_SIZE_NX150(ActorUniqueName, 0x30);

class Actor : public BaseProc, public ActorMessageTransceiver::IHandler {
public:
    enum class ModelObjectAttribute {
        MagneTarget = 0x1,
        MagneGrabbed = 0x2,
        CanBeStasised = 0x4,
        InStasis = 0x8,
        StasisTargeted = 0x10,
        IceBlock = 0x40,
        IceBlockTargeted = 0x80,
        RadarTarget = 0x800,
        InfoNotTree = 0x1000,
    };

    // Bit indices into the 64-bit mActorFlags word.
    enum class ActorFlag {
        PhysicsHeldForStaticCompound = 0,
        UpdatePhysicsPause = 1,
        SetPhysicsMtx = 2,
        DisableUpdateMtxFromPhysics = 3,
        UndispCut = 4,
        ModelBind = 5,
        WakeWithCreatorProc = 6,
        ELinkSleptForDelete = 7,
        HasUMii = 8,
        StopTimerReactionPending = 9,
        UnloadedByDistance = 10,
        EffectModelDeleteRequested = 11,
        AlwaysXlinkEmitted = 12,
        LodPhysicsInactivePrevMaybe = 13,
        KeepGenGroupAlive = 14,
        GenGroupWaitingForExec = 15,
        GenGroupExistCounted = 16,
        ForbidAttention = 17,
        EnableForbidPushJob = 18,
        DisableForbidPushJob = 19,
        ForceResetPreActorOnUnlink = 20,
        InInvalidTimeOrWeather = 21,
        TimeOrWeatherChecked = 22,
        IsLinkTagComplexTagEventTagAreaManagement = 23,
        StoppedByEvent = 24,
        DropsPreloaded = 25,
        ScheduleCalculated = 26,
        LodForbidPushJob = 27,
        ForceCalcInEvent = 28,
        IsCameraOrEditCamera = 29,
        WokenUp = 30,
        DeletedForReset = 31,
        DisableHideNonDemoMember = 32,
        FadeOutDeleteRequested = 33,
        EmitChangeAtnSig = 34,
        AppearFade = 35,
        PreDeletePhysicsRemoved = 36,
        InCarryBox = 37,
        WakeUpDistanceChecked = 38,
        WakeUpDistancePassed = 39,
        FirstDrawDone = 40,
        AutoPlaced = 41,
        AutoPlacedUntracked = 42,
        Invisible = 43,
        InFlight = 44,
        DisableForbidJob = 45,
        ReadyForPreDelete = 46,
        CreatedWithGenGroup = 47,
        ScheduleRainState = 48,
        VillagerMgrRegisterTried = 49,
        VillagerOutsideLoadArea = 50,
        AnimalTimeline = 51,
        NearDoor = 52,
        CreatedByObjectLink = 53,
        DeletedByObjectLink = 54,
        UsesOverlayPlayerAnimation = 55,
        StartNoDraw = 56,
        CharacterLike = 57,
        KeepStandingPosture = 58,
        MovedFromHome = 59,
        CalledEventStarted = 60,
        CalledEventDeferredInAir = 61,
        FrozenByEvent = 63,
    };

    enum class ActorFlag2 : u32 {
        SystemHide = 0x1,
        WakeUpReadyChecked = 0x2,
        InstEventFlag = 0x8,
        AnimDrivenRoot = 0x10,
        Invisible = 0x20,
        InStasis = 0x40,
        NoDistanceCheck = 0x80,
        DisableClipping = 0x100,
        PauseMenuActor = 0x200,
        PhysicsPaused = 0x400,
        ClothJobArmor = 0x800,
        ClothJobDefault = 0x1000,
        ForbidSystemDeleteDistance = 0x2000,
        KeepWhileModelBound = 0x4000,
        UnloadCountsAsDeath = 0x8000,
        NoStopTimer = 0x10000,
        PreparingAppear = 0x20000,
        NpcTalkTurnPlaying = 0x40000,
        EventMember = 0x100000,
        DemoEventMember = 0x200000,
        ModelObjectAttributesDirty = 0x400000,
        KeepActiveNearFireOrBowAim = 0x800000,
        Attention = 0x1000000,
        Notice = 0x2000000,
        Dead = 0x4000000,
        Escape = 0x8000000,
        GuardJust = 0x10000000,
        Carried = 0x40000000,
        InReaction = 0x80000000,
    };

    enum class DeleteType {
        Normal = 1,
        GenGroup = 2,
        PreActor = 3,
        Dead = 4,
        DeadNoCount = 5,
    };

    explicit Actor(const CreateArg& arg);
    ~Actor() override;

    SEAD_RTTI_OVERRIDE(Actor, BaseProc)

public:
    const sead::SafeString& getProfile() const;
    const char* getUniqueName() const;

    ai::RootAi* getRootAi() const { return mRootAi; }
    const ActorParam* getParam() const { return mActorParam; }
    map::PreActor* getMapObject() const { return mMapObject; }
    const map::MubinIter& getMapObjIter() const { return mMapObjIter; }
    as::ASList* getASList() const { return mASList; }

    const sead::Matrix34f& getMtx() const { return mMtx; }
    const sead::Vector3f& getVelocity() const { return mVelocity; }
    const sead::Vector3f& getAngVelocity() const { return mAngVelocity; }
    const sead::Vector3f& getScale() const { return mScale; }
    phys::RigidBody* getMainBody() const { return mMainBody; }
    phys::RigidBody* getTgtBody() const { return mTgtBody; }

    const MesTransceiverId* getMesTransceiverId() const { return mMsgTransceiver.getId(); }
    void sendMessage(const MesTransceiverId& dest, const MessageType& type, void* user_data,
                     bool ack);

    f32 getDeleteDistance() const {
        return sead::Mathf::sqrt(sead::Mathf::clampMin(mDeleteDistanceSq, 0.0f));
    }

    void setDeleteDistance(f32 distance) { mDeleteDistanceSq = sead::Mathf::square(distance); }

    phys::CharacterController* getCharacterController();

    void clearFlag(ActorFlag flag);
    bool checkFlag(ActorFlag flag) const;
    void setFlag(ActorFlag flag);
    void setFlag(ActorFlag flag, bool on);
    bool fadeoutDelete(DeleteType type, DeleteReason reason, bool* ok = nullptr);

    void setProperties(int x, const sead::Matrix34f& mtx, const sead::Vector3f& vel,
                       const sead::Vector3f& ang_vel, const sead::Vector3f& scale, bool keep_life,
                       int i, int life) const;

    // FIXME: figure out return types, parameters and names
    virtual s32 getMaxLife();
    virtual void getParentActor();
    virtual void getParentActorConst();
    virtual void hasCustomBoundingSphere();
    virtual void getBoundingSphere();
    virtual void updateImpulseInfo();
    virtual void applyImpulse();
    virtual void getGuardableAngle();
    virtual void getMass();
    virtual void getSubModelNum();
    virtual void getSubModel();
    virtual void getPhysicsMtx();
    virtual void onSetMtx();
    virtual void setRigidBodiesFixed();
    virtual void updateNavMeshCharacter();
    virtual void getNavMeshCharacter();
    virtual void* m46();
    virtual void removeExtraPhysicsFromWorld();
    virtual void getAttackerActor();
    virtual void isAlreadyHitOrLinkedActorBody();
    virtual void isStruckByLightning();
    virtual void setIgnoreChemicalElements();
    virtual void getChemicalPos();
    virtual bool isDamageStatusUpdateSuspended();
    virtual void killWithDropsAndEffects(int emit_type);
    virtual void receivesStasisDamage();
    virtual void getBodyCenterPos();
    virtual void isInStasis();
    virtual void onPreFadeoutDelete();
    virtual void onFadeOutSleep();
    virtual void onCancelFadeOutSleep();
    virtual void onModelOpacityApplied();
    virtual bool shouldUnload(DeleteReason* reason);
    virtual void enterCalcSetup();
    virtual void onEnterCalcInit();
    virtual void takeOverFromLodActor();
    virtual void reloadPlacementParamsForDebug();
    virtual void onCreateModel();
    virtual void refreshModelPoseAndAttentionBones();
    virtual void preCalc();
    virtual void preCalcPaused();
    virtual void postCalc();
    virtual void postCalcPaused();
    virtual void postSensorCalc();
    virtual void requestDraw();
    virtual void frameEndCalc();
    virtual void preCalcBegin();
    virtual void postCalcBegin();
    virtual void afterModelMatrixUpdate();
    virtual void postCalcEnd();
    virtual bool handleAck_();
    virtual void handleActorMessage();
    virtual int getCalcTiming();
    virtual void shouldUpdateCharacterController();
    virtual void updateMtxFromPhysics();
    virtual void setMtx();
    virtual void shouldUpdateCloth();
    virtual s32* getLife();
    virtual void updateAttentionPos();
    virtual void updateLookAtPos();
    virtual void updateGameCameraPos();
    virtual void updateObstacleCheckPos();
    virtual void onMaxPositionExceeded();
    virtual void requestNoticeUIState(int a1, float a2);
    virtual void getNoticeUIState();
    virtual s32 m95(void* arg, s32 value);
    virtual void getReceivedDamage();
    virtual Chemical* getMainChemical();
    virtual void getWeapons();
    virtual void getArmors();
    virtual void getCarriedInfo();
    virtual void getPartsActorList();
    virtual int getExtraHeapSize();
    virtual void destroyModelsMaybe();
    int handleMessage(const Message& message) override;
    void handleAck(const MessageAck& ack) override;
    virtual bool shouldShareSLinkEmitter();
    virtual void forceJobPushes();
    virtual void initMaterialAnim();
    virtual void getMaxASSlotCount();
    virtual void getCameraAlphaHideShallow();
    virtual void getCameraAlphaHideShallowInstant();
    virtual void getCameraAlphaHideDeep();
    virtual void getCameraAlphaHideDeepInstant();
    virtual void updateAS();
    virtual void adjustAnimPose();
    virtual void updateASKeys();
    virtual void forwardEventJoinRequest();
    virtual void setStoppedByEvent();
    virtual void getIkController();
    virtual void playAS();
    virtual void isASFinished();
    virtual void getModelMtx();
    virtual bool m123();
    virtual void onPreActorReset();
    virtual void getAtk();
    virtual void getContactCollector();
    virtual IncomingDamageHandler* getDamageMgr();
    virtual void getMagneComponent();
    virtual void getIPlayer();
    virtual void getRideInfo();
    virtual void getRideable();
    virtual void getRideableUnchecked();
    virtual void getRiderLink();
    virtual void getDropData();
    virtual void getDieInfo();
    virtual LifeRecoverInfo* getLifeRecoverInfo();
    virtual void isAttackCalcDelegatedToParent();
    virtual void isDamageCalcDelegatedToParent();
    virtual void getModelOpacity();
    virtual void isAttackActive();
    virtual void getHeldWeapon();
    virtual void isHeldByEnemy();
    virtual void connectActorEditorNode();
    virtual void disconnectActorEditorNode();
    virtual void beforeModelMatrixUpdate();
    virtual void calcBoneControl();
    virtual void fixupLinkedActorArray();

    sead::Atomic<u8>& getInWaterFlags() { return mInWaterFlags; }
    float getWaterSurfaceHeight() const { return mWaterSurfaceHeight; }

    void emitBasicSigOn();
    void emitBasicSigOff();
    bool checkBasicSig() const;

    void nullsub_4649();  // Some kind of logging which has been excluded from the build?

    sead::TypedBitFlag<ActorFlag2, s32>& getActorFlags2() { return mActorFlags2; }
    const sead::TypedBitFlag<ActorFlag2, s32>& getActorFlags2() const { return mActorFlags2; }

    void onAiEnter(const char* name, const char* context);

    static constexpr size_t getCreatorListNodeOffset() {
        return offsetof(Actor, mCreatorActorListNode);
    }

protected:
    friend class ActorCreator;

    struct ModelUserData {
        Actor* actor;
        u32 model_index;
    };

    void preCalcJob();
    void preCalcPausedJob();
    void postBgJob();
    void postBgPausedJob();
    void postSensorJob();
    void postSensorPausedJob();
    void frameEndJob();

    /* 0x190 */ sead::Atomic<phys::RigidBody*> mMainBody = nullptr;
    /* 0x198 */ sead::Atomic<phys::RigidBody*> mTgtBody = nullptr;
    /* 0x1a0 */ void* mEventBindingEntry = nullptr;
    /* 0x1a8 */ void* mEventFlowActorSlot = nullptr;
    /* 0x1b0 */ ModelUserData mModelUserData;
    /* 0x1c0 */ u32 _1c0 = 3;

    /* 0x1c8 */ BaseProcJobHandlerDualT<Actor> mPreCalcJob{this, &Actor::preCalcJob,
                                                           &Actor::preCalcPausedJob};
    /* 0x238 */ BaseProcJobHandlerDualT<Actor> mPostBgJob{this, &Actor::postBgJob,
                                                          &Actor::postBgPausedJob};
    /* 0x2a8 */ BaseProcJobHandlerDualT<Actor> mPostSensorJob{this, &Actor::postSensorJob,
                                                              &Actor::postSensorPausedJob};
    /* 0x318 */ BaseProcJobHandlerT<Actor> mFrameEndJob{this, &Actor::frameEndJob};

    /* 0x368 */ sead::ListNode mActiveActorListNode;
    /* 0x378 */ sead::ListNode mActorsThatLostPreActorListNode;
    /* 0x388 */ sead::ListNode mVillagerListNode;

    /* 0x398 */ sead::Matrix34f mMtx = sead::Matrix34f::ident;
    /* 0x3c8 */ sead::Matrix34f* mPhysicsMtx = nullptr;
    /* 0x3d0 */ sead::Matrix34f mHomeMtx = sead::Matrix34f::ident;
    /* 0x400 */ sead::Vector3f mVelocity{0, 0, 0};
    /* 0x40c */ sead::Vector3f mAngVelocity{0, 0, 0};
    /* 0x418 */ sead::Vector3f mScale{1, 1, 1};
    /* 0x424 */ float mDispDistanceSq;
    /* 0x428 */ float mDeleteDistanceSq = -1.0;
    /* 0x42c */ float mLoadDistanceSq = -1.0;
    /* 0x430 */ sead::Vector3f mAttentionPos{0, 0, 0};
    /* 0x43c */ sead::Vector3f mLookAtPos{0, 0, 0};
    /* 0x448 */ sead::Vector3f mCursorAIInfoBasePos{0, 0, 0};
    /* 0x454 */ sead::Vector3f mCutTargetPos{0, 0, 0};
    /* 0x460 */ sead::Vector3f mGameCameraPos{0, 0, 0};
    /* 0x46c */ sead::Vector3f mBowCameraPos{0, 0, 0};
    /* 0x478 */ sead::Vector3f mAttackTargetPos;
    /* 0x484 */ sead::Vector3f mObstacleCheckPos{0, 0, 0};
    /* 0x490 */ float mCursorOffsetY = 0.0;
    /* 0x494 */ float mAiInfoOffsetY = 0.0;
    /* 0x498 */ gsys::BoneAccessKey mLookAtBoneKey;
    /* 0x49c */ gsys::BoneAccessKey mCursorAIInfoBaseBoneKey;
    /* 0x4a0 */ gsys::BoneAccessKey mCutTargetBoneKey;
    /* 0x4a4 */ gsys::BoneAccessKey mGameCameraBoneKey;
    /* 0x4a8 */ gsys::BoneAccessKey mBowCameraBoneKey;
    /* 0x4ac */ gsys::BoneAccessKey mAttackTargetBoneKey;
    /* 0x4b0 */ gsys::BoneAccessKey mObstacleCheckBoneKey;
    /* 0x4b4 */ sead::Vector3f mMainBodyLocalCenter{0, 0, 0};
    /* 0x4c0 */ sead::Vector3f mTgtBodyLocalCenter{0, 0, 0};

    /* 0x4d0 */ ModelBindInfo* mModelBindInfo = nullptr;
    /* 0x4d8 */ void* mBoneHandles = nullptr;
    /* 0x4e0 */ gsys::Model* mModel = nullptr;
    /* 0x4e8 */ float mCameraHideAlpha = 1.0;
    /* 0x4ec */ float mFadeOpacity = 0.0;
    /* 0x4f0 */ float mModelOpacity = 1.0;
    /* 0x4f4 */ float mWarpEffectValue = 0.0;
    /* 0x4f8 */ float mFadeInDelay = 0.0;
    /* 0x4fc */ float _4fc = 0.0;
    /* 0x500 */ sead::BoundBox3f mAabb{sead::Vector3f::zero, sead::Vector3f::zero};

    /* 0x518 */ sead::TypedBitFlag<ActorFlag2, s32> mActorFlags2{};
    /* 0x51c */ sead::TypedBitFlag<ActorFlag2, s32> mActorFlags2Prev{};
    /* 0x520 */ util::AtomicLongBitFlag<64, ActorFlag> mActorFlags{};

    /* 0x528 */ PhysicsUserTag mPhysicsUserTag{this};
    /* 0x540 */ sead::Atomic<bool> mUnloadedOutOfPlacementArea = false;

    /* 0x548 */ void* mAwarenessSourceHolder = nullptr;
    /* 0x550 */ AwarenessInstance* mAwarenessInstance = nullptr;
    /* 0x558 */ ai::RootAi* mRootAi = nullptr;
    /* 0x560 */ as::ASList* mASList = nullptr;
    /* 0x568 */ xlink::ActorEffects* mActorEffects = nullptr;
    /* 0x570 */ ActorParam* mActorParam = nullptr;
    /* 0x578 */ phys::InstanceSet* mPhysics = nullptr;
    /* 0x580 */ PhysicsConstraints mConstraints;
    /* 0x598 */ LodState* mLodState = nullptr;
    /* 0x5a0 */ BoneControl* mBoneControl = nullptr;
    /* 0x5a8 */ phys::StaticCompoundRigidBodyGroup* mFieldBodyGroup = nullptr;
    /* 0x5b0 */ void* mExtraAnimResList = nullptr;
    /* 0x5b8 */ sead::Heap* mActorHeap = nullptr;
    /* 0x5c0 */ sead::Heap* mActorFrameHeap = nullptr;
    /* 0x5c8 */ sead::Heap* mParentHeap = nullptr;
    /* 0x5d0 */ ActorUniqueName* mUniqueName = nullptr;
    /* 0x5d8 */ Attention* mAttention = nullptr;
    /* 0x5e0 */ ActorMessageTransceiver mMsgTransceiver{*this, this};
    /* 0x638 */ Schedule* mSchedule = nullptr;

    /* 0x640 */ u32 mHashId = 0;
    /* 0x648 */ map::MubinIter mMapObjIter;

    /* 0x658 */ res::ModelResourceTextureCache* mModelTextureCache = nullptr;
    /* 0x660 */ sead::Buffer<res::ModelTextureBinding*> mModelTextureBindings;
    /* 0x670 */ sead::Buffer<res::Handle> mModelResHandles;
    /* 0x680 */ u8 mNumLoadedModelRes = 0;
    /* 0x681 */ u8 mNumModelBfres = 0;
    /* 0x682 */ u8 mPreDeleteModelReadyFrames = 0;
    /* 0x683 */ u8 mStableSignalFrames = 0;
    /* 0x684 */ u8 mForceJobPushTimer = 0;
    /* 0x685 */ sead::BitFlag8 mJobTypesRunMask;
    /* 0x686 */ s8 mStasisTraceEffectIdx = -1;
    /* 0x687 */ sead::Atomic<bool> mRecreateRequested = false;
    /* 0x688 */ sead::Atomic<bool> mKeepLifeOnEnterCalc = false;
    /* 0x689 */ sead::Atomic<bool> mAttentionDisabled = false;
    /* 0x68a */ sead::Atomic<bool> mApplyVelocityOnEnterCalc = false;
    /* 0x68b */ sead::Atomic<bool> mNoFadeInCreate = false;
    /* 0x68c */ sead::Atomic<u8> mModelFadeOutState = 0;
    /* 0x68d */ sead::Atomic<u8> mCameraAlphaHideMode = 0;
    /* 0x68e */ sead::Atomic<bool> mModelOpacityDirty = false;
    /* 0x68f */ sead::Atomic<u8> mInWaterFlags = 0;
    /* 0x690 */ u8 mPrevInWaterFlags = 0;
    /* 0x691 */ u8 mWaterContactFlags = 0;
    /* 0x694 */ sead::Atomic<int> mFadeoutDeleteType = 0;
    /* 0x698 */ sead::Atomic<u32> mFadeOutSleepFlags;
    /* 0x6a0 */ void* mWorldInfo = nullptr;
    /* 0x6a8 */ chm::ObjectSet* mChemicals = nullptr;
    /* 0x6b0 */ reaction::ActorReactions* mActorReactions = nullptr;
    /* 0x6b8 */ void* mContactReactionUnit = nullptr;
    /* 0x6c0 */ UMiiModelLink mUMiiModelLink{this};
    /* 0x6d0 */ float mDeleteEffectWaitTimer = 0.0;
    /* 0x6d8 */ void* mEffectModelEntry = nullptr;
    /* 0x6e0 */ float mWaterHitEffectTimer = 0.0;
    /* 0x6e4 */ float mWaterReactionTimer = 0.0;
    /* 0x6e8 */ float mLogWaterSplashTimer = -1.0;
    /* 0x6ec */ int mWaterFlowSplashTimer = 0;
    /* 0x6f0 */ float mWaterSurfaceHeight = -1.0;
    /* 0x6f4 */ float mWaterSubmergedRatio = 0.0;
    /* 0x6f8 */ float mPrevWaterSubmergedRatio = 0.0;
    /* 0x6fc */ int mWaterMaterial = 0;
    /* 0x700 */ int mWaterSubMaterial = 0;
    /* 0x708 */ ImpulseBaseProcLink* mImpulseBaseProcLink = nullptr;
    /* 0x710 */ sead::TypedBitFlag<ModelObjectAttribute> mModelObjectAttributes;
    /* 0x714 */ float mLodLoadDistanceMultiplier = 1.0;
    /* 0x718 */ float mCancelDeleteWaitTimer = 0.0;
    /* 0x71c */ sead::BitFlag32 mSignals;
    /* 0x720 */ sead::Atomic<s32> mNumAttachedConstraints = 0;
    /* 0x728 */ void* mEventExtraAnimHolder = nullptr;
    /* 0x730 */ u16 mFrustumCullRadius = 0;
    /* 0x732 */ sead::BitFlag16 mDrawDistanceFlags;
    /* 0x738 */ BaseProcLink mReplacementActorLink;
    /* 0x748 */ BaseProcLink mCreateArgBaseProcLink;
    /* 0x758 */ void* mSpawnerCallback = nullptr;
    /* 0x760 */ xlink2::Handle mAlwaysEffectHandle;
    /* 0x770 */ xlink2::Handle _770;
    /* 0x780 */ xlink2::Handle mSwordBlurHandle;
    /* 0x790 */ xlink2::Handle _790;
    /* 0x7a0 */ sead::Vector3f _7a0 = sead::Vector3f::zero;

    /* 0x7b0 */ ActorCreator* mCreator{};
    /* 0x7b8 */ sead::ListNode mCreatorActorListNode;
    /* 0x7c8 */ map::PreActor* mMapObject{};

    /* 0x7d0 */ void* mEventTransAnimData = nullptr;
    /* 0x7d8 */ bool mActorEditorNodeConnected = false;

    /* 0x7e0 */ ActorEditorNode mActorEditorNode;
    /* 0x810 */ sead::Buffer<void*> mUMiiBones;  // FIXME: type
    /* 0x820 */ mii::UMii* mUMii = nullptr;
    /* 0x828 */ mii::HylianInfo* mUMiiHylianInfo = nullptr;

    /* 0x830 */ float mUMiiRootHeightScale = 1.0;
    /* 0x834 */ int mUMiiMouthType = 0;
    /* 0x838 */ int mUMiiEyebrowType = 0;

private:
    enum class HandleMessageResult {
        _0,
        _1,
        _2,
    };

    HandleMessageResult doHandleMessage_(const Message& message);
};
KSYS_CHECK_SIZE_NX150(Actor, 0x840);

BaseProcLink& getDummyBaseProcLink();

}  // namespace act

}  // namespace ksys
