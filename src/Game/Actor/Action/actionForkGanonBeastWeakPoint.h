#pragma once

#include "Game/Actor/Action/actionForkSetEndState.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkGanonBeastWeakPoint : public ForkSetEndState {
    SEAD_RTTI_OVERRIDE(ForkGanonBeastWeakPoint, ForkSetEndState)
public:
    explicit ForkGanonBeastWeakPoint(const InitArg& arg);
    ~ForkGanonBeastWeakPoint() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x30
    const int* mTargetSlotIdx_s{};
    // aitree_variable at offset 0x38
    bool* mIsWeakPointAppearMode_a{};
    // aitree_variable at offset 0x40
    void* mWeakPointActiveFlag_a{};
    // aitree_variable at offset 0x48
    void* mWeakPointAliveFlag_a{};
};

}  // namespace uking::action
