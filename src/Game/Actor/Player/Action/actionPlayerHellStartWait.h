#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerHellStartWait : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerHellStartWait, PlayerBase)
public:
    explicit PlayerHellStartWait(const InitArg& arg);
    ~PlayerHellStartWait() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
