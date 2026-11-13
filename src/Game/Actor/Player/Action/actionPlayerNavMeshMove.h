#pragma once

#include "Game/Actor/Player/Action/actionPlayerDestinationMoveBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerNavMeshMove : public PlayerDestinationMoveBase {
    SEAD_RTTI_OVERRIDE(PlayerNavMeshMove, PlayerDestinationMoveBase)
public:
    explicit PlayerNavMeshMove(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
