#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerAtnWait : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerAtnWait, PlayerBase)
public:
    explicit PlayerAtnWait(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mAtnTurnDiffAng_s{};
};

}  // namespace uking::action
