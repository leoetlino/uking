#pragma once

#include "Game/Actor/Player/Action/actionPlayerDestinationMoveBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerDestinationMove : public PlayerDestinationMoveBase {
    SEAD_RTTI_OVERRIDE(PlayerDestinationMove, PlayerDestinationMoveBase)
public:
    explicit PlayerDestinationMove(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x58
    float* mDestPosX_d{};
    // dynamic_param at offset 0x60
    float* mDestPosY_d{};
    // dynamic_param at offset 0x68
    float* mDestPosZ_d{};
};

}  // namespace uking::action
