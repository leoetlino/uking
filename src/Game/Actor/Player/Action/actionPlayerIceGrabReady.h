#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerIceGrabReady : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerIceGrabReady, PlayerBase)
public:
    explicit PlayerIceGrabReady(const InitArg& arg);
    ~PlayerIceGrabReady() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
