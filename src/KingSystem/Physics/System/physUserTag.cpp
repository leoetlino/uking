#include "KingSystem/Physics/System/physUserTag.h"
#include "KingSystem/Physics/RigidBody/physRigidBody.h"

namespace ksys::phys {

void UserTag::onMaxPositionExceeded(RigidBody* body) {
    body->onMaxPositionExceeded();
}

void UserTag::onImpulse(RigidBody* body_a, RigidBody* body_b, float impulse_a) {
    body_a->onImpulse(body_b, impulse_a);
}

void UserTag::onBodyShapeChanged(RigidBody* body) {}

void UserTag::onWaterContact(const WaterContactRequest& request) {}

void UserTag::onInvalidParameter(RigidBody* body, int code) {}

}  // namespace ksys::phys
