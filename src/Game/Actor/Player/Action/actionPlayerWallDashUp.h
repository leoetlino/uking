#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerWallDashUp : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerWallDashUp, PlayerBase)
public:
    explicit PlayerWallDashUp(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mJumpHeight_s{};
    // static_param at offset 0x28
    const float* mMinSpeedF_s{};
    // static_param at offset 0x30
    const float* mMaxSpeedF_s{};
};

}  // namespace uking::action
