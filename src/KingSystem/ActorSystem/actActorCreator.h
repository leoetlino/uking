#pragma once

#include <container/seadOffsetList.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>
#include <prim/seadDelegate.h>
#include <thread/seadCriticalSection.h>
#include "KingSystem/Framework/frmActorInstParamPack.h"
#include "KingSystem/Utils/Thread/Task.h"
#include "KingSystem/Utils/Thread/TaskQueueBase.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::map {
class MubinIter;
}  // namespace ksys::map

namespace ksys::frm {
class BaseProc;
struct BaseProcCreateArg;
class BaseProcHandle;
}  // namespace ksys::frm

namespace ksys::act {

class Actor;
struct ActorCreateArg;
class PreActor;

class IBaseProcFactory {
public:
    virtual void dummy() = 0;
    virtual frm::BaseProc* createActor(const ActorCreateArg& arg) = 0;
    virtual void dummy2() = 0;
};

class ActorCreator {
    SEAD_SINGLETON_DISPOSER(ActorCreator)
    ActorCreator();
    virtual ~ActorCreator();

public:
    bool requestCreateMapActor(const char* name, sead::Heap* heap, map::MubinIter* mubin_iter,
                               PreActor* map_object, frm::BaseProcHandle* handle, int task_lane_id,
                               frm::ActorInstParamPack* params);
    Actor* createActor(const char* name, sead::Heap* heap, frm::ActorInstParamPack* params,
                       bool sleep_after_init, bool block_other_synchronous_spawns);
    bool requestCreateActor(const char* name, sead::Heap* heap, frm::BaseProcHandle* handle,
                            frm::ActorInstParamPack* params, PreActor* map_object,
                            int task_lane_id);

    void enableDistanceUnloadChecks();
    void eraseActor(Actor* actor);

    void setBaseProcFactory(IBaseProcFactory* factory) { mBaseProcFactory = factory; }
    bool get5a() const { return _5a; }

    sead::OffsetList<Actor>& getActorList() { return mActorList; }
    sead::CriticalSection& getCS() { return mActorListCS; }

    static void addScale(frm::ActorInstParamPack& pack, float scale);
    static void addScale(frm::ActorInstParamPack& pack, const sead::Vector3f& scale);
    static bool isAITreeParam(const frm::ActorInstParamPack::Entry& entry);
    static void addAITreeParam(frm::ActorInstParamPack& pack, const sead::SafeString& value,
                               const sead::SafeString& name);
    static void addAITreeParam(frm::ActorInstParamPack& pack, int value,
                               const sead::SafeString& name);
    static void addAITreeParam(frm::ActorInstParamPack& pack, u32 value,
                               const sead::SafeString& name);
    static void addAITreeParam(frm::ActorInstParamPack& pack, bool value,
                               const sead::SafeString& name);
    static void setCreatePriorityState1(frm::ActorInstParamPack& pack, frm::BaseProc* proc);
    static void setCreatePriorityState2(frm::ActorInstParamPack& pack, frm::BaseProc* proc);

private:
    bool requestCreateActor_(const char* actor_class, const char* name, sead::Heap* heap,
                             map::MubinIter* mubin_iter, PreActor* map_object,
                             frm::BaseProcHandle* handle, int task_lane_id,
                             frm::ActorInstParamPack* params);
    bool requestCreateActor_(const char* actor_class, const char* name, sead::Heap* heap,
                             PreActor* map_object, frm::BaseProcHandle* handle, int task_lane_id,
                             frm::ActorInstParamPack* params);
    frm::BaseProc* createActor_(const char* actor_class, const char* name, sead::Heap* heap,
                                frm::ActorInstParamPack* params, bool sleep_after_init,
                                bool = false);

    frm::BaseProc* doCreateProc(frm::BaseProcCreateArg& arg);
    void onTaskRemoved(const TaskRemoveCallbackContext& context);

    sead::Heap* mForBaseProcDualHeap;
    sead::Heap* mPlacementMgrHeap;
    sead::OffsetList<Actor> mActorList;
    void* _50{};
    bool mEnableDistanceChecks;
    bool mBlockSpawns;
    bool _5a;
    void* _60{};
    sead::Delegate1R<ActorCreator, frm::BaseProcCreateArg&, frm::BaseProc*> mCreateProcDelegate{
        this, &ActorCreator::doCreateProc};
    TaskRemoveCallbackT<ActorCreator> mTaskRemovedDelegate{this, &ActorCreator::onTaskRemoved};
    sead::CriticalSection mActorListCS;
    IBaseProcFactory* mBaseProcFactory;
};
KSYS_CHECK_SIZE_NX150(ActorCreator, 0xf0);

class BaseProcCreateTaskSelector {
    SEAD_SINGLETON_DISPOSER(BaseProcCreateTaskSelector)
    BaseProcCreateTaskSelector() = default;

public:
    auto& getDelegate() { return mDelegate; }

private:
    Task* selectTask(const TaskSelectionContext& context);

    TaskSelectionDelegateT<BaseProcCreateTaskSelector> mDelegate{
        this, &BaseProcCreateTaskSelector::selectTask};
};
KSYS_CHECK_SIZE_NX150(BaseProcCreateTaskSelector, 0x40);

}  // namespace ksys::act
