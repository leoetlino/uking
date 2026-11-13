#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerStopInAir : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerStopInAir, PlayerBase)
public:
    explicit PlayerStopInAir(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    bool* mNoFixed_d{};
};

}  // namespace uking::action
