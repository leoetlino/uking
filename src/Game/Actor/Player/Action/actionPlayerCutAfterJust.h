#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerCutAfterJust : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerCutAfterJust, PlayerBase)
public:
    explicit PlayerCutAfterJust(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mSlowContTime_s{};
    // static_param at offset 0x28
    const float* mLastCutAcceptTime_s{};
    // static_param at offset 0x30
    const float* mLastCutAcceptTimeLSword_s{};
    // static_param at offset 0x38
    const float* mLastCutAcceptTimeSpear_s{};
    // static_param at offset 0x40
    const float* mForceSlowTime_s{};
};

}  // namespace uking::action
