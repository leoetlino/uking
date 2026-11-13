#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerDestinationTurn : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerDestinationTurn, PlayerBase)
public:
    explicit PlayerDestinationTurn(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    float* mDestPosX_d{};
    // dynamic_param at offset 0x28
    float* mDestPosY_d{};
    // dynamic_param at offset 0x30
    float* mDestPosZ_d{};
};

}  // namespace uking::action
