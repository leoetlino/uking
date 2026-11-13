#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerUnequip : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerUnequip, PlayerBase)
public:
    explicit PlayerUnequip(const InitArg& arg);
    ~PlayerUnequip() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
