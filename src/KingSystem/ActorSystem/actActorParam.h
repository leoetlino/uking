#pragma once

#include <array>
#include <container/seadBuffer.h>
#include <heap/seadDisposer.h>
#include <hostio/seadHostIONode.h>
#include <prim/seadSafeString.h>
#include <thread/seadCriticalSection.h>
#include "KingSystem/ActorSystem/actActorLink.h"
#include "KingSystem/Framework/frmBaseProcMgrJob.h"
#include "KingSystem/Resource/resHandle.h"
#include "KingSystem/Utils/Thread/Event.h"

namespace ksys {

class ParamIO;

namespace res {
class EventFlow;
}  // namespace res

namespace act {

class ActorParamMgr;
class AIProgram;
class AISchedule;
class AnimInfo;
class ASList;
class AttClientList;
class Awareness;
class BoneControl;
class Chemical;
class DamageParam;
class Drop;
class GParamList;
class LifeCondition;
class Lod;
class ModelList;
class Physics;
class RagdollBlendWeight;
class RagdollConfigResource;
class RagdollConfigList;
class Recipe;
class Shop;
class UMii;

// FIXME: incomplete
class ActorParam : public sead::hostio::Node {
public:
    enum class ResourceType {
        ActorLink = 0,
        ModelList = 1,
        ASList = 2,
        AIProgram = 3,
        GParamList = 4,
        Physics = 5,
        Chemical = 6,
        AttClientList = 7,
        AISchedule = 8,
        EventFlow = 9,
        DamageParam = 10,
        RagdollConfigList = 11,
        RagdollBlendWeight = 12,
        Awareness = 13,
        Unknown14 = 14,
        Unknown15 = 15,
        Unknown16 = 16,
        DropTable = 17,
        ShopData = 18,
        Recipe = 19,
        Lod = 20,
        BoneControl = 21,
        LifeCondition = 22,
        UMii = 23,
        AnimationInfo = 24,
        AS = 25,
        AttClient = 26,
        RagdollConfig = 27,
    };
    static constexpr s32 NumResourceTypes = 28;

    static constexpr bool isValidType(ResourceType type) {
        return type <= ResourceType::AnimationInfo;
    }

    union Resources {
        struct {
            ActorLink* mActorLink;
            ModelList* mModelList;
            ASList* mASList;
            AIProgram* mAIProgram;
            GParamList* mGParamList;
            Physics* mPhysics;
            Chemical* mChemical;
            AttClientList* mAttClientList;
            AISchedule* mAISchedule;
            res::EventFlow* mEventFlow;
            DamageParam* mDamageParam;
            RagdollConfigList* mRagdollConfigList;
            RagdollBlendWeight* mRagdollBlendWeight;
            Awareness* mAwareness;
            void* mResource14;
            void* mResource15;
            void* mResource16;
            Drop* mDropTable;
            Shop* mShopData;
            Recipe* mRecipe;
            Lod* mLod;
            BoneControl* mBoneControl;
            LifeCondition* mLifeCondition;
            UMii* mUMii;
            AnimInfo* mAnimationInfo;
        };
        sead::SafeArray<ParamIO*, 25> mArray;
    };
    KSYS_CHECK_SIZE_NX150(Resources, 0xc8);

    ActorParam();
    virtual ~ActorParam();

    const sead::SafeString& getActorName() const { return mActorName; }
    const sead::SafeString& getProfile() const { return mProfile; }
    const char* getClassName() const { return mClassName; }
    frm::CalcPrio getPriority() const { return mPriority; }
    const Resources& getRes() const { return mRes; }

    bool isA() const { return _a; }

    bool isDummyParam(ActorLink::User user) const;

    static void resetDummyResources();

    static Resources sDummyResources;

private:
    friend class ActorParamMgr;

    void deleteData();
    void deleteResHandles();

    void allocResHandles(sead::Heap* heap, u32 buffer_idx, s32 count);

    s32 incrementRef();
    s32 decrementRef();

    void setEventSignal();
    void waitForEvent();
    bool isSignalSet() const;
    int updateResource(const char* data, char* data1, char* data2);

    res::Handle* allocHandle();
    void freeLastHandle();

    void setResource(ResourceType type, ParamIO* param_io);
    bool setPriority(const sead::SafeString& priority);
    void setProfileAndPriority(const char* profile, const char* priority);

    void setResourceIfValidType(ResourceType type, ParamIO* param_io) {
        if (isValidType(type))
            setResource(type, param_io);
    }

    void onLoadFinished(ActorParamMgr* mgr);

    u8 _8 = 0;
    u8 _9 = 0;
    bool _a = false;
    sead::FixedSafeString<64> mActorName;
    sead::SafeString mProfile;
    const char* mClassName{};
    frm::CalcPrio mPriority = frm::CalcPrio::AllAfter;
    u32 mActiveBufferIdx = 2;
    Resources mRes;
    std::array<sead::Buffer<res::Handle>, 2> mHandles;
    std::array<s32, 2> mNumHandles;
    s32 mRefCount{};
    sead::CriticalSection mCS{nullptr};
    Event mEvent{nullptr, sead::IDisposer::HeapNullOption::DoNotAppendDisposerIfNoHeapSpecified,
                 true};
};
KSYS_CHECK_SIZE_NX150(ActorParam, 0x200);

}  // namespace act

}  // namespace ksys
