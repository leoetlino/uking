#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerSwimJump : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerSwimJump, PlayerBase)
public:
    explicit PlayerSwimJump(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mJumpHeight_s{};
    // static_param at offset 0x28
    const float* mJumpSpeedF_s{};
    // static_param at offset 0x30
    const float* mEnergyJump_s{};
};

}  // namespace uking::action
