#pragma once

#include <basis/seadTypes.h>
#include "KingSystem/ActorSystem/actPreActor.h"
#include "KingSystem/Resource/resResourceBinder.h"
#include "KingSystem/Utils/Types.h"

namespace al {
class ByamlIter;
}

namespace ksys::act {
class Actor;
class PreActor;
}  // namespace ksys::act

namespace ksys::frm {
class ActorInstParamPack;
}  // namespace ksys::frm

namespace ksys::game {

enum class WeaponModifier {
    None = 0,
    /// This will be upgraded to Blue randomly.
    RandomBlue = 1,
    Blue = 2,
    Yellow = 3,
    /// Chests only: Weapon will never spawn with any modifiers. This overrides regular scaling.
    NoneForced = 4,
};

// TODO Find out where this goes. It is currently used by ksys::game::LevelSensor::scaleActor.
WeaponModifier getRandomWeaponModifier(s32 judge_type, const sead::SafeString& unit_config_name);

class LevelSensor {
public:
    LevelSensor();
    virtual ~LevelSensor();

    void init(sead::Heap* heap);

    bool scaleWeapon(const sead::SafeString& weapon, WeaponModifier min_modifier,
                     const char** scaled_weapon, WeaponModifier* scaled_modifier,
                     const act::Actor* actor) const;

    bool scaleActor(const sead::SafeString& name, act::PreActor* obj, const char** scaled_weapon,
                    frm::ActorInstParamPack* pack, const sead::Vector3f& position) const;

    void calculatePoints();

private:
    bool isScalingAllowed(const sead::Vector3f& position) const;
    bool isScalingAllowed(const act::Actor& actor) const;

    f32 mPoints{};
    f32 mWeaponPoints{};
    f32 mEnemyPoints{};
    bool _14{};
    f32 mDefaultPoints = -1;
    al::ByamlIter* mRootIter = nullptr;
    res::ResourceBinder mResHandle;
};
KSYS_CHECK_SIZE_NX150(LevelSensor, 0x78);

}  // namespace ksys::game
