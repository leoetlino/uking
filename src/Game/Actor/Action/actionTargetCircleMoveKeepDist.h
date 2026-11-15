#pragma once

#include "Game/Actor/Action/actionTargetCircleMove.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class TargetCircleMoveKeepDist : public TargetCircleMove {
    SEAD_RTTI_OVERRIDE(TargetCircleMoveKeepDist, TargetCircleMove)
public:
    explicit TargetCircleMoveKeepDist(const InitArg& arg);
    ~TargetCircleMoveKeepDist() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x80
    sead::SafeString mASName_s{};
};

}  // namespace uking::action
