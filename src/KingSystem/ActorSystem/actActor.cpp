#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/ActorSystem/actActorParam.h"
#include "KingSystem/ActorSystem/actBaseProcLink.h"
#include "KingSystem/ActorSystem/actBaseProcMgr.h"
#include "KingSystem/ActorSystem/aiRootAi.h"
#include "KingSystem/Physics/System/physInstanceSet.h"

namespace ksys::act {

namespace {
BaseProcLink sDummyBaseProcLink;
}  // namespace

BaseProcLink& getDummyBaseProcLink() {
    return sDummyBaseProcLink;
}

Actor::Actor(const CreateArg& arg) : BaseProc(arg) {
    mJobHandlers[BaseProcMgr::getPreCalcJobType()] = &mPreCalcJob;
    mJobHandlers[BaseProcMgr::getPostBgJobType()] = &mPostBgJob;
    mJobHandlers[BaseProcMgr::getPostSensorJobType()] = &mPostSensorJob;
    mJobHandlers[BaseProcMgr::getFrameEndJobType()] = &mFrameEndJob;

    mModelUserData.actor = this;
    mModelUserData.model_index = 0;
}

Actor::~Actor() {
    // FIXME
}

void Actor::clearFlag(Actor::ActorFlag flag) {
    mActorFlags.resetBit(flag);
}

bool Actor::checkFlag(Actor::ActorFlag flag) const {
    return mActorFlags.isOnBit(flag);
}

void Actor::setFlag(Actor::ActorFlag flag) {
    setFlag(flag, true);
}

void Actor::setFlag(Actor::ActorFlag flag, bool on) {
    mActorFlags.changeBit(flag, on);
}

const sead::SafeString& Actor::getProfile() const {
    return mActorParam->getProfile();
}

const char* Actor::getUniqueName() const {
    const char* unique_name = nullptr;

    if (mMapObjIter.tryGetParamStringByKey(&unique_name, "UniqueName"))
        return unique_name;

    if (mUniqueName && mUniqueName->unique_name)
        unique_name = mUniqueName->unique_name->cstr();

    return unique_name;
}

void Actor::handleAck(const MessageAck& ack) {
    if (handleAck_())
        return;

    if (mRootAi)
        mRootAi->handleAck(ack);
}

int Actor::handleMessage(const Message& message) {
    const auto result = doHandleMessage_(message);
    switch (result) {
    default:
        return 0;
    case HandleMessageResult::_1:
        return 1;
    case HandleMessageResult::_2:
        forceJobPushes();
        return 1;
    }
}

phys::CharacterController* Actor::getCharacterController() {
    if (!mPhysics)
        return nullptr;
    return mPhysics->getCharacterController();
}

}  // namespace ksys::act
