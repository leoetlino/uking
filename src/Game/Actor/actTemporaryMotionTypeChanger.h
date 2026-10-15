#pragma once

#include <basis/seadTypes.h>

namespace ksys::act {
class Actor;
}

namespace ksys::phys {
class CharacterController;
}

namespace uking::act {

// todo: move?
enum class MotionType {
    Hover = 3,
};

class TemporaryMotionTypeChanger {
public:
    TemporaryMotionTypeChanger();
    ~TemporaryMotionTypeChanger();

    void changeMotionType(ksys::phys::CharacterController* cc, MotionType motion_type);
    void resetRigidBodyMotion(ksys::act::Actor* actor);
    void resetMotionType(ksys::phys::CharacterController* cc);
    void saveFlags(ksys::phys::CharacterController* cc);
    void restoreSavedFlags(ksys::phys::CharacterController* cc);

private:
    MotionType mSavedMotionType{};
    u8 mSavedFlagMask{};
    u8 mSavedFlags{};
};

}  // namespace uking::act
