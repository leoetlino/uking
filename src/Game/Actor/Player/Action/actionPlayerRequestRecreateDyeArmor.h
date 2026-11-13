#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerRequestRecreateDyeArmor : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerRequestRecreateDyeArmor, PlayerBase)
public:
    explicit PlayerRequestRecreateDyeArmor(const InitArg& arg);
    ~PlayerRequestRecreateDyeArmor() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
};

}  // namespace uking::action
