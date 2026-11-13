#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class BackStepBase : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(BackStepBase, act::ActionEx)
public:
    explicit BackStepBase(const InitArg& arg);
    ~BackStepBase() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mStopSpeedRatio_s{};
    // static_param at offset 0x28
    const float* mStopRotSpeedRatio_s{};
    // static_param at offset 0x30
    const float* mJumpGravity_s{};
    // static_param at offset 0x38
    const float* mJumpHeight_s{};
    // static_param at offset 0x40
    const float* mRotRatio_s{};
    // static_param at offset 0x48
    const bool* mCheckRotEvent_s{};
    // dynamic_param at offset 0x50
    sead::Vector3f* mTargetPos_d{};
};

}  // namespace uking::action
