#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerTurnInner : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerTurnInner, PlayerBase)
public:
    explicit PlayerTurnInner(const InitArg& arg);
    ~PlayerTurnInner() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
