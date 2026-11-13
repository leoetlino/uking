#pragma once

#include "Game/Actor/Action/actionForkDropWeaponWithSpeedBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkDropWeaponWithSpeed : public ForkDropWeaponWithSpeedBase {
    SEAD_RTTI_OVERRIDE(ForkDropWeaponWithSpeed, ForkDropWeaponWithSpeedBase)
public:
    explicit ForkDropWeaponWithSpeed(const InitArg& arg);
    ~ForkDropWeaponWithSpeed() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
