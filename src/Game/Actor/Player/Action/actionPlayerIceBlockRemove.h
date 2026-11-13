#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerIceBlockRemove : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerIceBlockRemove, PlayerBase)
public:
    explicit PlayerIceBlockRemove(const InitArg& arg);
    ~PlayerIceBlockRemove() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
