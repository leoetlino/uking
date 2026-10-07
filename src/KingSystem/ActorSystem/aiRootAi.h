#pragma once

#include <prim/seadBitFlag.h>
#include <thread/seadAtomic.h>
#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/ActorSystem/actAiBehavior.h"
#include "KingSystem/ActorSystem/actAiParam.h"
#include "KingSystem/ActorSystem/actAiQueries.h"
#include "KingSystem/ActorSystem/actAiQuery.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act::ai {

class IRootAi {
public:
    virtual ~IRootAi() = default;
};

enum class RootAiFlag {
    ReturnFromDamage = 0,
    ReturnFromGuard = 1,
    _2 = 2,
    _3 = 3,
    ReturnFromRebound = 4,
    WaitingForEventStart = 5,
    RequestDemoRootChild = 6,
    RequestNormalRootChild = 7,
    ChildChanged = 8,
    ExternalImpulsePending = 9,
};

// TODO: rename
enum class RootAiFlag2 {};

class RootAi : public Ai, public IRootAi {
    SEAD_RTTI_OVERRIDE(RootAi, Ai)
public:
    explicit RootAi(const InitArg& arg);
    ~RootAi() override;

    bool isChangeable() const override { return true; }
    bool init_(sead::Heap* heap) override;
    void enter_(InlineParamPack* params) override;
    void leave_() override;
    bool handleMessage_(const Message& message) override;
    void calc() override;

    const ParamPack& getMapUnitParams() const { return mMapUnitParams; }
    const ParamPack& getAiTreeParams() const { return mAiTreeParams; }
    u32 getI() const { return mI; }
    bool isActorDeletedOrDeleting() const;

    const Actions& getActions() const { return mActions; }
    const Ais& getAis() const { return mAis; }
    const Behaviors& getBehaviors() const { return mBehaviors; }
    const Queries& getQueries() const { return mQueries; }

    bool loadMapUnitParams(const AIDef& def, sead::Heap* heap);
    bool loadAITreeParams(const AIDef& def, sead::Heap* heap);

    bool getMapUnitParam(sead::SafeString* value, const sead::SafeString& key) const;
    bool getMapUnitParam(const s32** value, const sead::SafeString& key) const;
    bool getMapUnitParam(const f32** value, const sead::SafeString& key) const;
    bool getMapUnitParam(const sead::Vector3f** value, const sead::SafeString& key) const;
    bool getMapUnitParam(const bool** value, const sead::SafeString& key) const;

    bool getAITreeVariable(sead::SafeString** value, const sead::SafeString& key) const;
    bool getAITreeVariable(s32** value, const sead::SafeString& key) const;
    bool getAITreeVariable(f32** value, const sead::SafeString& key) const;
    bool getAITreeVariable(sead::Vector3f** value, const sead::SafeString& key) const;
    bool getAITreeVariable(bool** value, const sead::SafeString& key) const;
    bool getAITreeVariable(void** value, const sead::SafeString& key) const;
    bool getAITreeVariable(u32** value, const sead::SafeString& key) const;
    // TODO: rename
    bool getAITreeVariable2(sead::Vector3f** value, const sead::SafeString& key) const;
    // TODO: rename
    bool getAITreeVariable2(bool** value, const sead::SafeString& key) const;

    void setBehavior(Behavior* behavior);
    void resetBehavior(Behavior* behavior);

private:
    friend class ActionBase;

    // TODO: put this in a different translation unit
    struct EventActionContextList {
        EventActionContextList();
        virtual ~EventActionContextList();

        void* mEventActionContexts{};
    };
    KSYS_CHECK_SIZE_NX150(EventActionContextList, 0x10);

    void calc_() override;

    f32 mChemicalScale = 1.0;
    u32 mLastModelIceRatio{};
    Actions mActions;
    Ais mAis;
    Behaviors mBehaviors;
    Queries mQueries;
    sead::SafeArray<Behavior*, 3> mBehaviorsByStopAndCalcTiming[2]{};
    void* mPendingBehaviors{};
    EventActionContextList* mEventActionContexts{};
    u32 mI{};
    u16 mAt{};
    u8 mPreDeleteDone{};
    void* _150{};
    void* _158{};
    void* _160{};
    // TODO: is this really an atomic?
    sead::Atomic<f32> mExternalImpulseScale = 1.0;
    // RootAiFlag
    sead::BitFlag16 mFlags;
    // RootAiFlag2
    sead::BitFlag16 mPrevFlags;
    ParamPack mMapUnitParams;
    ParamPack mAiTreeParams;
};
KSYS_CHECK_SIZE_NX150(RootAi, 0x180);

const char* getDefaultAiName(s32 root_idx);
const char* getDefaultActionName(s32 idx);

inline const char* getDefaultName(ActionType type, s32 idx) {
    if (type == ActionType::AI)
        return getDefaultAiName(idx);
    return getDefaultActionName(idx);
}

}  // namespace ksys::act::ai
