#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerDestinationTurnRefActor : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerDestinationTurnRefActor, PlayerBase)
public:
    explicit PlayerDestinationTurnRefActor(const InitArg& arg);
    ~PlayerDestinationTurnRefActor() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    sead::SafeString mUniqName_d{};
};

}  // namespace uking::action
