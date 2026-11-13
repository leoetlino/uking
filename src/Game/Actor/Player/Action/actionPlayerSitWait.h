#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerSitWait : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerSitWait, PlayerBase)
public:
    explicit PlayerSitWait(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mAutoRecoverRate_s{};
    // static_param at offset 0x28
    const float* mEnergyAutoRecover_s{};
};

}  // namespace uking::action
