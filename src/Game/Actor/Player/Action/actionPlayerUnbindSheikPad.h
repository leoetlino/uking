#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerUnbindSheikPad : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerUnbindSheikPad, PlayerBase)
public:
    explicit PlayerUnbindSheikPad(const InitArg& arg);
    ~PlayerUnbindSheikPad() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
};

}  // namespace uking::action
