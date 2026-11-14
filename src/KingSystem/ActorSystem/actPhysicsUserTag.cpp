#include "KingSystem/ActorSystem/actPhysicsUserTag.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/Framework/frmBaseProcAccessor.h"
#include "KingSystem/Framework/frmBaseProcMgr.h"

namespace ksys::act {

PhysicsUserTag::PhysicsUserTag(Actor* actor) : mActor(actor) {}

PhysicsUserTag::~PhysicsUserTag() = default;

Actor* PhysicsUserTag::getActor(frm::BaseProcAccessor* accessor, Actor* other_actor) const {
    if (mActor != nullptr) {
        if (mActor != other_actor &&
            !frm::BaseProcMgr::instance()->isAccessingProcSafe(mActor, nullptr))
            return mActor;
        if (!frm::acquireProc(accessor, mActor, "act::PhysicsUserTag"))
            return nullptr;
    }
    return mActor;
}

bool PhysicsUserTag::acquireActor(frm::BaseProcAccessor* accessor) const {
    return accessor->acquire(mActor);
}

const sead::SafeString& PhysicsUserTag::getName() const {
    return mActor->getName();
}

const sead::SafeString& PhysicsUserTag::getName(phys::RigidBody* rigid_body) const {
    return getName();
}

}  // namespace ksys::act
