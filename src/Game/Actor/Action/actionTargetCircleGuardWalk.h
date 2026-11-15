#pragma once

#include "Game/Actor/Action/actionTargetCircleMove.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class TargetCircleGuardWalk : public TargetCircleMove {
    SEAD_RTTI_OVERRIDE(TargetCircleGuardWalk, TargetCircleMove)
public:
    explicit TargetCircleGuardWalk(const InitArg& arg);

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
