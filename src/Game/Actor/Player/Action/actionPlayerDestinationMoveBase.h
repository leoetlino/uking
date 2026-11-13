#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerDestinationMoveBase : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerDestinationMoveBase, PlayerBase)
public:
    explicit PlayerDestinationMoveBase(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mDecSpdDist_s{};
    // dynamic_param at offset 0x28
    float* mStickValue_d{};
    // static_param at offset 0x30
    const float* mForceTurnDist_s{};
};

}  // namespace uking::action
