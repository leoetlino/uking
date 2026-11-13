#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerEquipHaveMasterSword : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerEquipHaveMasterSword, PlayerBase)
public:
    explicit PlayerEquipHaveMasterSword(const InitArg& arg);
    ~PlayerEquipHaveMasterSword() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
