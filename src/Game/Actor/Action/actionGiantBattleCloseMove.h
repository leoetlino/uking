#pragma once

#include "Game/Actor/Action/actionGiantBattleCloseMoveAction.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class GiantBattleCloseMove : public GiantBattleCloseMoveAction {
    SEAD_RTTI_OVERRIDE(GiantBattleCloseMove, GiantBattleCloseMoveAction)
public:
    explicit GiantBattleCloseMove(const InitArg& arg);
    ~GiantBattleCloseMove() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
