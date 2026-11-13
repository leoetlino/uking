#pragma once

#include "Game/Actor/Player/Action/actionPlayerDestinationMoveBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerRailMove : public PlayerDestinationMoveBase {
    SEAD_RTTI_OVERRIDE(PlayerRailMove, PlayerDestinationMoveBase)
public:
    explicit PlayerRailMove(const InitArg& arg);
    ~PlayerRailMove() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x58
    sead::SafeString mRailName_d{};
};

}  // namespace uking::action
