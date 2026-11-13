#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerLaunch : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerLaunch, PlayerBase)
public:
    explicit PlayerLaunch(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const float* mInitSpeed_s{};
    // static_param at offset 0x28
    const float* mJumpHeight_s{};
    // static_param at offset 0x30
    const float* mAddLinearImpulse_s{};
    // static_param at offset 0x38
    const float* mAddRollImpulse_s{};
    // static_param at offset 0x40
    const float* mNoRagdollTime_s{};
    // static_param at offset 0x48
    const int* mDamage_s{};
    // dynamic_param at offset 0x50
    sead::Vector3f* mBasePos_d{};
};

}  // namespace uking::action
