#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerSetVisibleWeapon : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerSetVisibleWeapon, PlayerBase)
public:
    explicit PlayerSetVisibleWeapon(const InitArg& arg);
    ~PlayerSetVisibleWeapon() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x20
    bool* mSetVisible_d{};
};

}  // namespace uking::action
