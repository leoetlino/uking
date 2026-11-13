#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerWaterDivingJump : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerWaterDivingJump, PlayerBase)
public:
    explicit PlayerWaterDivingJump(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mDiveSpeedF_s{};
    // static_param at offset 0x28
    const float* mDiveHeight_s{};
    // static_param at offset 0x30
    const float* mDiveSpeedDec_s{};
};

}  // namespace uking::action
