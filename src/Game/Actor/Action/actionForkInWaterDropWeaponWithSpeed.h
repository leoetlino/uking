#pragma once

#include "Game/Actor/Action/actionForkDropWeaponWithSpeedBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkInWaterDropWeaponWithSpeed : public ForkDropWeaponWithSpeedBase {
    SEAD_RTTI_OVERRIDE(ForkInWaterDropWeaponWithSpeed, ForkDropWeaponWithSpeedBase)
public:
    explicit ForkInWaterDropWeaponWithSpeed(const InitArg& arg);
    ~ForkInWaterDropWeaponWithSpeed() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x48
    const float* mInWaterDepth_s{};
    // static_param at offset 0x50
    const float* mOutWaterDepth_s{};
};

}  // namespace uking::action
