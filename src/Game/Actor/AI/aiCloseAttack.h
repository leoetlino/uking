#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"

namespace uking::ai {

class CloseAttack : public ksys::act::ai::Ai {
    SEAD_RTTI_OVERRIDE(CloseAttack, ksys::act::ai::Ai)
public:
    explicit CloseAttack(const InitArg& arg);
    ~CloseAttack() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    // static_param at offset 0x38
    const float* mCloseRadius_s{};
    // static_param at offset 0x40
    const int* mWeaponIdx_s{};
    // static_param at offset 0x48
    const bool* mIsIgnoreSmallHit_s{};
    // dynamic_param at offset 0x50
    sead::Vector3f* mTargetPos_d{};
};

}  // namespace uking::ai
