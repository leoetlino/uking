#pragma once

#include "KingSystem/Physics/RigidBody/physRigidBody.h"

namespace ksys::tera {
class Scene;
}

namespace ksys::phys {

class TerrainHeightFieldRigidBody : public RigidBody {
    SEAD_RTTI_OVERRIDE(TerrainHeightFieldRigidBody, RigidBody)
public:
    bool shouldScaleCharacterContactImpulse() const { return mScaleCharacterContactImpulse; }

private:
    tera::Scene* mTeraScene{};
    bool mScaleCharacterContactImpulse = false;
};

}  // namespace ksys::phys
