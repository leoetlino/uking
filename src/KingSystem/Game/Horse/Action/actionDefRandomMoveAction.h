#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/ActorSystem/actionRandomMoveAction.h"

namespace ksys::game {

class DefRandomMoveAction : public ksys::act::ai::RandomMoveAction {
    SEAD_RTTI_OVERRIDE(DefRandomMoveAction, ksys::act::ai::RandomMoveAction)
public:
    explicit DefRandomMoveAction(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x38
    const float* mRadiusLimit_s{};
    // static_param at offset 0x40
    const float* mMaxMoveSpeed_s{};
    // static_param at offset 0x48
    const float* mMinMoveSpeed_s{};
    // static_param at offset 0x50
    const float* mMaxMoveDistance_s{};
    // static_param at offset 0x58
    const float* mMinMoveDistance_s{};
    // static_param at offset 0x60
    const float* mMaxMoveAngle_s{};
    // static_param at offset 0x68
    const bool* mIsUseBasepos_s{};
    // dynamic_param at offset 0x70
    sead::Vector3f* mBasePos_d{};
};

}  // namespace ksys::game
