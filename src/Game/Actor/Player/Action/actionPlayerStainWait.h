#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerStainWait : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerStainWait, PlayerBase)
public:
    explicit PlayerStainWait(const InitArg& arg);
    ~PlayerStainWait() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
