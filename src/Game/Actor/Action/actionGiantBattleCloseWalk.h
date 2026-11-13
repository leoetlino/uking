#pragma once

#include "Game/Actor/Action/actionGiantBattleCloseMoveAction.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class GiantBattleCloseWalk : public GiantBattleCloseMoveAction {
    SEAD_RTTI_OVERRIDE(GiantBattleCloseWalk, GiantBattleCloseMoveAction)
public:
    explicit GiantBattleCloseWalk(const InitArg& arg);
    ~GiantBattleCloseWalk() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
