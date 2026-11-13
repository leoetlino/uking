#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerGrabThrow : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerGrabThrow, PlayerBase)
public:
    explicit PlayerGrabThrow(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mOverThrowSpeedYB_s{};
    // static_param at offset 0x28
    const float* mOverThrowSpeedFB_s{};
    // static_param at offset 0x30
    const float* mOverThrowSpeedYL_s{};
    // static_param at offset 0x38
    const float* mOverThrowSpeedFL_s{};
    // static_param at offset 0x40
    const float* mOverThrowInertiaRate_s{};
};

}  // namespace uking::action
