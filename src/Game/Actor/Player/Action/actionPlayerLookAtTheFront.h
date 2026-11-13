#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerLookAtTheFront : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerLookAtTheFront, PlayerBase)
public:
    explicit PlayerLookAtTheFront(const InitArg& arg);
    ~PlayerLookAtTheFront() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x20
    bool* mIsValid_d{};
};

}  // namespace uking::action
