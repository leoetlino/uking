#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerGuardJust : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerGuardJust, PlayerBase)
public:
    explicit PlayerGuardJust(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mForceSlowTime_s{};
};

}  // namespace uking::action
