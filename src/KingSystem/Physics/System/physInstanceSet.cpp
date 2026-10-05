#include "KingSystem/Physics/System/physInstanceSet.h"
#include "KingSystem/Physics/CharacterController/physCharacterController.h"
#include "KingSystem/Physics/Ragdoll/physRagdollInstance.h"
#include "KingSystem/Physics/RigidBody/physRigidBodySet.h"
#include "KingSystem/Physics/System/physCollisionInfo.h"
#include "KingSystem/Physics/System/physContactPointInfo.h"
#include "KingSystem/Resource/Actor/resResourceRagdollBlendWeight.h"

namespace ksys::phys {

void InstanceSet::requestTransformReset() {
    mFlags.set(Flag::TransformResetRequested);
    if (mClothSet != nullptr) {
        mFlags.set(Flag::TransformResetRequested);
        mFlags.set(Flag::ClothResetRequested);
    }
}

void InstanceSet::requestClothReset() {
    if (mClothSet != nullptr) {
        mFlags.set(Flag::ClothResetRequested);
    }
}

void InstanceSet::setInDemo() {
    mFlags.set(Flag::InDemo);
}

void InstanceSet::resetInDemo() {
    mFlags.reset(Flag::InDemo);
}

void InstanceSet::setClothResetMode(s32 mode) {
    if (mFlags.isOn(Flag::InDemo))
        return;

    switch (mode) {
    case -2:
        mFlags.reset(Flag::ClothResetCancelled);
        mFlags.set(Flag::ClothResetIfMoved);
        break;
    case -1:
        mFlags.reset(Flag::ClothTeleportInsteadOfReset);
        mFlags.reset(Flag::ClothResetCancelled);
        mFlags.reset(Flag::ClothResetIfMoved);
        mFlags.set(Flag::ClothResetCancelled);
        mFlags.set(Flag::ClothTeleportInsteadOfReset);
        break;
    case 0:
        mFlags.reset(Flag::ClothResetIfMoved);
        mFlags.reset(Flag::ClothResetCancelled);
        mFlags.set(Flag::ClothTeleportInsteadOfReset);
        break;
    case 1:
        mFlags.reset(Flag::ClothResetIfMoved);
        mFlags.reset(Flag::ClothResetCancelled);
        mFlags.reset(Flag::ClothTeleportInsteadOfReset);
        break;
    }
}

void InstanceSet::copyClothResetModeFrom(InstanceSet* other) {
    if (other == nullptr)
        return;

    u32 mode = other->getClothResetMode();
    setClothResetMode(mode);
}

u32 InstanceSet::getClothResetMode() const {
    u32 idx;
    if (mFlags.isOn(Flag::ClothResetIfMoved)) {
        idx = -2;
    } else if (mFlags.isOn(Flag::ClothResetCancelled)) {
        idx = -1;
    } else if (mFlags.isOn(Flag::ClothTeleportInsteadOfReset)) {
        idx = 0;
    } else {
        idx = 1;
    }
    return idx;
}

void InstanceSet::addToWorld() {
    for (auto& rb : mRigidBodySets) {
        rb.addToWorld();
    }

    for (auto& body : mExtraRigidBodies) {
        body->addToWorld();
    }

    if (mCharacterController != nullptr)
        mCharacterController->addRigidBodyToWorld();
}

void InstanceSet::disableContactLayer(phys::ContactLayer layer) {
    bool sensor = phys::getContactLayerType(layer) != ContactLayerType::Entity;

    for (auto& rb : mRigidBodySets) {
        rb.disableContactLayer(layer);
    }
    if (sensor)
        return;

    if (mRagdollInstance != nullptr)
        mRagdollInstance->disableContactLayer(layer);

    if (mCharacterController != nullptr)
        mCharacterController->enableContactLayer(layer);
}

void InstanceSet::setContactNone() {
    for (auto& rb : mRigidBodySets) {
        rb.disableAllContactLayers();
    }
    if (mRagdollInstance != nullptr) {
        mRagdollInstance->setContactNone();
    }
    if (mCharacterController != nullptr) {
        mCharacterController->setContactNone();
    }
}

RigidBody* InstanceSet::getRigidBody(s32 rigid_body_set_idx, s32 rigid_body_idx) const {
    if (mRigidBodySets.size() <= rigid_body_set_idx)
        return nullptr;
    return mRigidBodySets[rigid_body_set_idx]->getRigidBody(rigid_body_idx);
}

void InstanceSet::resetBodyContactSettingsFromParam(phys::RigidBody* body,
                                                    phys::RigidBodyParam* param) {
    if (body == nullptr)
        return;

    phys::RigidBodyInstanceParam instance_params;
    param->makeInstanceParam(&instance_params);
    if (instance_params.contact_layer == phys::ContactLayer::SensorCustomReceiver) {
        body->setSensorCustomReceiver(instance_params.receiver_mask,
                                      mSystemGroupHandlers[body->isSensor()]);
    } else if (instance_params.groundhit_mask) {
        body->setGroundHitMask(instance_params.contact_layer, instance_params.groundhit_mask);
    } else {
        body->setContactLayerAndGroundHitAndHandler(instance_params.contact_layer,
                                                    instance_params.groundhit,
                                                    mSystemGroupHandlers[body->isSensor()]);
    }
    body->enableGroundCollision(instance_params.no_hit_ground == 0);
    body->enableWaterCollision(instance_params.no_hit_water == 0);
    body->clearSensorReceiverIgnoredLayer();
}

RigidBody* InstanceSet::findRigidBody(const sead::SafeString& name) const {
    for (auto& rb : mRigidBodySets) {
        RigidBody* p = rb.findBodyByHavokName(name);
        if (p != nullptr)
            return p;
    }
    return nullptr;
}

s32 InstanceSet::findContactPointInfo(const sead::SafeString& name) const {
    s32 idx = 0;
    for (auto& info : mContactPointInfo) {
        if (name == info.getName())
            return idx;
        idx++;
    }
    return -1;
}

s32 InstanceSet::findCollisionInfo(const sead::SafeString& name) const {
    s32 idx = 0;
    for (auto& info : mCollisionInfo) {
        if (name == info.getName())
            return idx;
        idx++;
    }
    return -1;
}

void InstanceSet::updateBodiesFromModelMatrix(const sead::Matrix34f& mtx) {
    if (mFlags.isOff(Flag::Active))
        return;

    if (mFlags.isOn(Flag::PoseSyncedThisFrame)) {
        updateBoneLinkedBodyTransforms(mtx, true, false);
    } else {
        mFlags.reset(Flag::TransformResetThisFrame);
        if (mFlags.isOn(Flag::TransformResetRequested))
            setMtxAndScale(mtx, false, false, mScale);
    }
    mFlags.reset(Flag::PoseSyncedThisFrame);

    if (mRagdollInstance == nullptr)
        return;

    if (mRagdollInstance->getWorldState() == RagdollInstance::WorldState::AddedToWorld)
        updateBoneLinkedBodyTransforms(mtx, false, false);
}

s32 InstanceSet::findRagdollControllerIdx(const sead::SafeString& name) const {
    if (mRagdollBlendWt == nullptr)
        return -1;

    s32 idx = mRagdollBlendWt->findStateIdx(name);
    if (idx >= 0)
        return idx + 2;

    if (name == "full_dynamic") {
        return 1;
    }
    if (name == "full_key_framed") {
        return 0;
    }

    return -1;
}

}  // namespace ksys::phys
