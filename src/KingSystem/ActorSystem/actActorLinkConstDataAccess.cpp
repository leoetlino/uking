#include "KingSystem/ActorSystem/actActorLinkConstDataAccess.h"
#include <prim/seadRuntimeTypeInfo.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectAttack.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectEnemy.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectHorseTargetedInfo.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectLiftable.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectSystem.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/ActorSystem/actActorParam.h"
#include "KingSystem/ActorSystem/actGParamList.h"
#include "KingSystem/ActorSystem/actPreActor.h"
#include "KingSystem/ActorSystem/aiRootAi.h"
#include "KingSystem/Framework/frmBaseProc.h"
#include "KingSystem/Game/Util/ActorUtil.h"

namespace ksys::act {

static frm::BaseProc* getProcIfActor(frm::BaseProc* proc) {
    if (proc && sead::IsDerivedFrom<Actor>(proc))
        return proc;
    return nullptr;
}

inline Actor* ActorLinkConstDataAccess::getActor() const {
    return static_cast<Actor*>(getProcIfActor(mProc));
}

bool ActorLinkConstDataAccess::acquireActor(const frm::BaseProcAccessor& other) {
    return acquire(getProcIfActor(other.mProc));
}

bool ActorLinkConstDataAccess::hasProc(frm::BaseProc* proc) const {
    return mProc == proc;
}

bool ActorLinkConstDataAccess::hasProc(const frm::BaseProcLink& link) const {
    return link.hasProcById(getActor());
}

bool ActorLinkConstDataAccess::linkAcquire(frm::BaseProcLink* link) const {
    auto* proc = getActor();
    if (proc)
        return link->acquire(proc, false);

    link->reset();
    return false;
}

bool ActorLinkConstDataAccess::linkAcquireImmediately(frm::BaseProcLink* link) const {
    auto* proc = getActor();
    if (proc)
        return link->acquire(proc, true);

    link->reset();
    return false;
}

bool ActorLinkConstDataAccess::isPlayerProfile() const {
    return game::isPlayerProfile(getActor());
}

bool ActorLinkConstDataAccess::isWeaponProfile() const {
    return game::isWeaponProfile(getActor());
}

bool ActorLinkConstDataAccess::isNPCProfile() const {
    return game::isNPCProfile(getActor());
}

bool ActorLinkConstDataAccess::isEnemyProfile() const {
    return game::isEnemyProfile(getActor());
}

const sead::SafeString& ActorLinkConstDataAccess::getProfile() const {
    auto* actor = getActor();
    return actor && actor->getParam() ? actor->getProfile() : sead::SafeString::cEmptyString;
}

void ActorLinkConstDataAccess::debugLog(s32, const sead::SafeString&) const {
    // Intentionally left empty.
}

const sead::SafeString& ActorLinkConstDataAccess::getName() const {
    auto* proc = getProcIfActor(mProc);
    if (!proc)
        return sead::SafeString::cEmptyString;
    return proc->getName();
}

const sead::SafeString& ActorLinkConstDataAccess::getLiftType() const {
    auto* actor = getActor();
    if (!actor)
        return sead::SafeString::cEmptyString;
    return actor->getParam()->getRes().mGParamList->getLiftable()->mLiftType.ref();
}

bool ActorLinkConstDataAccess::isDisableFreezeLift() const {
    auto* actor = getActor();
    if (!actor)
        return false;
    return actor->getParam()->getRes().mGParamList->getLiftable()->mDisableFreezeLift.ref();
}

bool ActorLinkConstDataAccess::isDisableBurnLift() const {
    auto* actor = getActor();
    if (!actor)
        return false;
    return actor->getParam()->getRes().mGParamList->getLiftable()->mDisableBurnLift.ref();
}

bool ActorLinkConstDataAccess::hasTag(const char* tag) const {
    auto* actor = getActor();
    if (!actor)
        return false;
    return actor->getParam()->getRes().mActorLink->hasTag(tag);
}

bool ActorLinkConstDataAccess::hasTag(u32 tag) const {
    auto* actor = getActor();
    if (!actor)
        return false;
    return actor->getParam()->getRes().mActorLink->hasTag(tag);
}

const char* ActorLinkConstDataAccess::getUniqueName() const {
    auto* actor = getActor();
    if (!actor)
        return nullptr;
    return actor->getUniqueName();
}

u32 ActorLinkConstDataAccess::getId() const {
    auto* proc = getActor();
    if (!proc)
        return 0xffffffff;
    return proc->getId();
}

bool ActorLinkConstDataAccess::acquireConnectedCalcParent(frm::BaseProcAccessor* accessor) const {
    auto* proc = getActor();
    if (!proc)
        return false;

    accessor->acquire(sead::DynamicCast<Actor>(proc->getConnectedCalcParent()));
    return accessor->mProc != nullptr;
}

bool ActorLinkConstDataAccess::acquireConnectedCalcChild(frm::BaseProcAccessor* accessor) const {
    auto* proc = getActor();
    if (!proc)
        return false;

    accessor->acquire(sead::DynamicCast<Actor>(proc->getConnectedCalcChild()));
    return accessor->mProc != nullptr;
}

bool ActorLinkConstDataAccess::hasConnectedCalcParent() const {
    auto* proc = getActor();
    return proc && sead::DynamicCast<Actor>(proc->getConnectedCalcParent()) != nullptr;
}

bool ActorLinkConstDataAccess::isInvisible() const {
    auto* actor = getActor();
    if (!actor)
        return false;
    return actor->checkFlag(Actor::ActorFlag::Invisible);
}

bool ActorLinkConstDataAccess::deleteLater(frm::BaseProc::DeleteReason reason) const {
    auto* actor = getActor();
    if (!actor)
        return false;
    return actor->deleteLater(reason);
}

bool ActorLinkConstDataAccess::fadeoutDelete(frm::BaseProc::DeleteReason reason) const {
    auto* actor = getActor();
    if (!actor)
        return false;
    return actor->fadeoutDelete(Actor::DeleteType::Normal, reason);
}

bool ActorLinkConstDataAccess::sleep(frm::BaseProc::SleepWakeReason reason) const {
    auto* actor = getActor();
    if (!actor)
        return false;
    actor->sleep(reason);
    return true;
}

bool ActorLinkConstDataAccess::wakeUp(frm::BaseProc::SleepWakeReason reason) const {
    auto* actor = getActor();
    if (!actor)
        return false;
    actor->wakeUp(reason);
    return true;
}

bool ActorLinkConstDataAccess::setProperties(int x, const sead::Matrix34f& mtx,
                                             const sead::Vector3f& vel,
                                             const sead::Vector3f& ang_vel,
                                             const sead::Vector3f& scale, bool keep_life, int i,
                                             int life) const {
    auto* actor = getActor();
    if (!actor)
        return false;
    actor->setProperties(x, mtx, vel, ang_vel, scale, keep_life, i, life);
    return true;
}

bool ActorLinkConstDataAccess::setProperties(const sead::Matrix34f& mtx, const sead::Vector3f& vel,
                                             const sead::Vector3f& ang_vel,
                                             const sead::Vector3f& scale, bool keep_life, int i,
                                             int life) const {
    return setProperties(0, mtx, vel, ang_vel, scale, keep_life, i, life);
}

bool ActorLinkConstDataAccess::isStateSleep() const {
    auto* actor = getActor();
    return actor && actor->isSleep();
}

bool ActorLinkConstDataAccess::isStateCalc() const {
    auto* actor = getActor();
    return actor && actor->isCalc();
}

bool ActorLinkConstDataAccess::isDeletedOrDeleting() const {
    auto* actor = getActor();
    return actor && actor->isDeletedOrDeleting();
}

GParamList* ActorLinkConstDataAccess::getGParamList() const {
    auto* actor = getActor();
    if (!actor)
        return nullptr;
    return actor->getParam()->getRes().mGParamList;
}

Shop* ActorLinkConstDataAccess::getShopData() const {
    auto* actor = getActor();
    if (!actor)
        return nullptr;
    return actor->getParam()->getRes().mShopData;
}

const sead::SafeString& ActorLinkConstDataAccess::getAttackSpHitActor() const {
    auto* actor = getActor();
    if (!actor)
        return sead::SafeString::cEmptyString;
    return actor->getParam()->getRes().mGParamList->getAttack()->mSpHitActor.ref();
}

const sead::SafeString& ActorLinkConstDataAccess::getAttackSpHitTag() const {
    auto* actor = getActor();
    if (!actor)
        return sead::SafeString::cEmptyString;
    return actor->getParam()->getRes().mGParamList->getAttack()->mSpHitTag.ref();
}

const sead::SafeString& ActorLinkConstDataAccess::getAttackWeakHitTag() const {
    auto* actor = getActor();
    if (!actor)
        return sead::SafeString::cEmptyString;
    return actor->getParam()->getRes().mGParamList->getAttack()->mSpWeakHitActor.ref();
}

f32 ActorLinkConstDataAccess::getAttackSpHitRatio() const {
    auto* actor = getActor();
    if (!actor)
        return 1.0f;
    return actor->getParam()->getRes().mGParamList->getAttack()->mSpHitRatio.ref();
}

s32 ActorLinkConstDataAccess::getAttackPower() const {
    auto* actor = getActor();
    if (!actor)
        return 0;
    return actor->getParam()->getRes().mGParamList->getAttack()->mPower.ref();
}

ObjectLinkData* ActorLinkConstDataAccess::getMapObjectLinkData() const {
    auto* actor = getActor();
    if (!actor)
        return nullptr;

    auto* object = actor->getMapObject();
    if (!object)
        return nullptr;

    return object->getLinkData();
}

PreActor* ActorLinkConstDataAccess::getMapObject() const {
    auto* actor = getActor();
    if (!actor)
        return nullptr;
    return actor->getMapObject();
}

s32 ActorLinkConstDataAccess::getEnemyRank() const {
    auto* actor = getActor();
    if (!actor)
        return 0;

    auto* gparam = actor->getParam()->getRes().mGParamList;
    if (!gparam || !gparam->getEnemy())
        return 0;

    return gparam->getEnemy()->mRank.ref();
}

bool ActorLinkConstDataAccess::getSameGroupActorName(sead::SafeString* name) const {
    auto* actor = getActor();
    if (!actor) {
        *name = sead::SafeString::cEmptyString;
        return false;
    }

    auto* gparam = actor->getParam()->getRes().mGParamList;
    if (!gparam || !gparam->getSystem()) {
        *name = actor->getName();
        return false;
    }

    const auto& group_name = gparam->getSystem()->mSameGroupActorName.ref();
    if (group_name.isEmpty()) {
        *name = actor->getName();
        return false;
    }

    *name = group_name;
    return true;
}

bool ActorLinkConstDataAccess::isStoppedByEvent() const {
    auto* actor = getActor();
    return actor && actor->checkFlag(Actor::ActorFlag::StoppedByEvent);
}

bool ActorLinkConstDataAccess::isPlayerTheConnectedParent() const {
    auto* actor = getActor();
    if (!actor)
        return false;

    auto* parent = sead::DynamicCast<Actor>(actor->getConnectedCalcParent());
    if (!parent)
        return false;

    return parent->getProfile() == "Player";
}

void ActorLinkConstDataAccess::setThisActorAsParent(frm::BaseProc* child,
                                                    bool delete_parent_on_delete) {
    auto* actor = getActor();
    if (!actor)
        return;
    child->setConnectedCalcParent(actor, delete_parent_on_delete);
}

void ActorLinkConstDataAccess::setThisActorAsChild(frm::BaseProc* parent,
                                                   bool delete_child_on_delete) {
    auto* actor = getActor();
    if (!actor)
        return;
    parent->setConnectedCalcChild(actor, delete_child_on_delete);
}

bool ActorLinkConstDataAccess::isFlyingBalloon() const {
    auto* actor = getActor();
    if (!actor)
        return false;
    bool* value;
    return actor->getRootAi()->getAITreeVariable(&value, "IsFlyingBalloon") && *value;
}

u32 ActorLinkConstDataAccess::getBalloonHungActorBaseProcID() const {
    auto* actor = getActor();
    if (!actor)
        return -1;
    int* value;
    if (!actor->getRootAi()->getAITreeVariable(&value, "BalloonHungActorBaseProcID"))
        return -1;
    return *value;
}

bool ActorLinkConstDataAccess::isInCarryBox() const {
    auto* actor = getActor();
    return actor && actor->checkFlag(Actor::ActorFlag::InCarryBox);
}

f32 ActorLinkConstDataAccess::getHorseMoveRadius() const {
    auto* actor = getActor();
    if (!actor)
        return -1.0;
    return actor->getParam()->getRes().mGParamList->getHorseTargetedInfo()->mHorseMoveRadius.ref();
}

f32 ActorLinkConstDataAccess::getHorseAvoidOffset() const {
    auto* actor = getActor();
    if (!actor)
        return -1.0;
    return actor->getParam()->getRes().mGParamList->getHorseTargetedInfo()->mHorseAvoidOffset.ref();
}

bool ActorLinkConstDataAccess::horseTargetedIsCircularMoveAlways() const {
    auto* actor = getActor();
    if (!actor)
        return false;
    auto* gparam = actor->getParam()->getRes().mGParamList;
    return gparam->getHorseTargetedInfo()->mIsCircularMoveAlways.ref();
}

const sead::Matrix34f& ActorLinkConstDataAccess::getActorMtx() {
    const Actor* actor = mProc ? sead::DynamicCast<Actor>(mProc) : nullptr;
    if (actor)
        return actor->getMtx();
    return sead::Matrix34f::ident;
}

}  // namespace ksys::act
