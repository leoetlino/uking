#pragma once

#include <prim/seadRuntimeTypeInfo.h>
#include <prim/seadSafeString.h>
#include "KingSystem/Utils/Types.h"

namespace ksys::phys {

struct FluidContactRequest;
class RigidBody;

class UserTag {
    SEAD_RTTI_BASE(UserTag)
public:
    UserTag() = default;

    /// Called when a rigid body goes beyond the broadphase border.
    /// The default implementation just notifies the rigid body of this callback.
    virtual void onMaxPositionExceeded(RigidBody* body);
    virtual void onImpulse(RigidBody* body_a, RigidBody* body_b, float impulse_a);
    virtual void onBodyShapeChanged(RigidBody* body);
    virtual void onWaterContact(const FluidContactRequest& request);
    virtual const sead::SafeString& getName() const { return sead::SafeString::cEmptyString; }
    virtual void onInvalidParameter(RigidBody* body, int code);
    virtual const sead::SafeString& getName(RigidBody* rigid_body) const {
        return sead::SafeString::cEmptyString;
    }
    virtual ~UserTag() = default;
};
KSYS_CHECK_SIZE_NX150(UserTag, 0x8);

}  // namespace ksys::phys
