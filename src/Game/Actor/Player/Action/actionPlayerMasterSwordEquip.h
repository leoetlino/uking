#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerMasterSwordEquip : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerMasterSwordEquip, PlayerBase)
public:
    explicit PlayerMasterSwordEquip(const InitArg& arg);
    ~PlayerMasterSwordEquip() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace uking::action
