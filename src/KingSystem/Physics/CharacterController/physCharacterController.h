#pragma once
#include "KingSystem/Physics/physDefines.h"

namespace ksys::phys {

class CharacterController {
public:
    void addRigidBodyToWorld();
    void setContactNone();
    void enableContactLayer(ContactLayer);
};

}  // namespace ksys::phys
