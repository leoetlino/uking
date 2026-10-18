#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>

namespace ksys::as {

enum class ASKey : u32 {
    StickValue = 0,
    StickX = 1,
    StickY = 2,
    RightStickValue = 3,
    RightStickX = 4,
    RightStickY = 5,
    StickAngle = 6,
    NoLoopStickAngle = 7,
    RightStickAngle = 8,
    DirectionAngle = 9,
    UserSpeed = 10,
    UserAngle = 11,
    UserAngle2 = 12,
    Tired = 13,
    Stress = 14,
    WallAngle = 15,
    Distance = 16,
    Size = 17,
    ForwardBent = 18,
    Speed = 19,
    YSpeed = 20,
    GroundNormal = 21,
    GroundNormalSide = 22,
    Temperature = 23,
    AbsTemperature = 24,
    Weight = 25,
    DiffAngleY = 26,
    WindVelocity = 27,
    Bone = 28,
    ZEx00Exposure = 29,
    Random = 30,
    FootFRLife = 31,
    FootFLLife = 32,
    FootBRLife = 33,
    FootBLLife = 34,
    Generation = 35,
    Mouth = 36,
    Eye = 37,
    Eyebrow = 38,
    SelfHeight = 39,
    SelfWeight = 40,
    DungeonNumber = 41,
    Charge = 42,
    Combo = 43,
    Weapon = 44,
    WeaponDetail = 45,
    Button = 46,
    Variation = 47,
    Attention = 48,
    GrabType = 49,
    Personality = 50,
    PreAS = 51,
    Time = 52,
    Weather = 53,
    Gear = 54,
    Emotion = 55,
    FaceEmotion = 56,
    Armor = 57,
    Mask = 58,
    Posture = 59,
    Arrow = 60,
    Ride = 61,
    UseItem = 62,
    NodePos = 63,
    DungeonClear = 64,
    EventFlag = 65,
    Bool = 66,
    None = 0xffffffff,
};

class ASList {
public:
    void startAnimationMaybe(f32 a2, f32 a3, const sead::SafeString& animation, int a5, int a6,
                             bool a7);
    bool setKeyString(u32 a1, const sead::SafeString& a2, u32 a3);
    s64 setBoolKeyBit(u32 a1, int a2, bool m, u32 a4);
    const sead::Vector3f* getAnimDrivenAngularVelocity();
};

}  // namespace ksys::as
