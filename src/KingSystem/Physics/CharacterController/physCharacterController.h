#pragma once
#include "KingSystem/Game/Physics/physDefines.h"

namespace ksys::phys {

class CharacterController {
public:
    enum class State {
        OnGround = 0,
        InAir = 1,
        Climbing = 2,
        FreeMoving = 3,
    };

    void addRigidBodyToWorld();
    void setContactNone();
    void enableContactLayer(ContactLayer);
};

}  // namespace ksys::phys
