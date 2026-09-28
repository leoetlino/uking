#pragma once
#include "KingSystem/ActorSystem/actActor.h"
namespace ksys::as {
class ASList {
public:
    void startAnimationMaybe(f32 a2, f32 a3, const sead::SafeString& animation, int a5, int a6,
                             bool a7);
    bool setKeyString(u32 a1, const sead::SafeString& a2, u32 a3);
    s64 setBoolKeyBit(u32 a1, int a2, bool m, u32 a4);
    const sead::Vector3f* getAnimDrivenAngularVelocity();
};

}  // namespace ksys::as
