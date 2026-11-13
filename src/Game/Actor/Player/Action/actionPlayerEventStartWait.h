#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerEventStartWait : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerEventStartWait, PlayerBase)
public:
    explicit PlayerEventStartWait(const InitArg& arg);
    ~PlayerEventStartWait() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
