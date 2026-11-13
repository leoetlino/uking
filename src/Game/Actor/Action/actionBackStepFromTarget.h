#pragma once

#include "Game/Actor/Action/actionBackStepBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class BackStepFromTarget : public BackStepBase {
    SEAD_RTTI_OVERRIDE(BackStepFromTarget, BackStepBase)
public:
    explicit BackStepFromTarget(const InitArg& arg);
    ~BackStepFromTarget() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0xc0
    const float* mJumpDist_s{};
};

}  // namespace uking::action
