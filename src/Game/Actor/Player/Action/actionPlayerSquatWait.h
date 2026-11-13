#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerSquatWait : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerSquatWait, PlayerBase)
public:
    explicit PlayerSquatWait(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mWaitTime_s{};
    // static_param at offset 0x28
    const float* mAtnTurnDiffAng_s{};
};

}  // namespace uking::action
