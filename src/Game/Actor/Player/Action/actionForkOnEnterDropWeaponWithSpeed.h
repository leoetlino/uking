#pragma once

#include "Game/Actor/Action/actionForkDropWeaponWithSpeedBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkOnEnterDropWeaponWithSpeed : public ForkDropWeaponWithSpeedBase {
    SEAD_RTTI_OVERRIDE(ForkOnEnterDropWeaponWithSpeed, ForkDropWeaponWithSpeedBase)
public:
    explicit ForkOnEnterDropWeaponWithSpeed(const InitArg& arg);
    ~ForkOnEnterDropWeaponWithSpeed() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
