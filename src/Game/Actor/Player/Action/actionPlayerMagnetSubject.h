#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerMagnetSubject : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerMagnetSubject, PlayerBase)
public:
    explicit PlayerMagnetSubject(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mDRCEnergy_s{};
};

}  // namespace uking::action
