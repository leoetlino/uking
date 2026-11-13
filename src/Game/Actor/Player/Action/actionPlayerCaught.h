#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerCaught : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerCaught, PlayerBase)
public:
    explicit PlayerCaught(const InitArg& arg);
    ~PlayerCaught() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
