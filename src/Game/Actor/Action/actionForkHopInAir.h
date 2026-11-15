#pragma once

#include "Game/Actor/Action/actionForkSetEndState.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkHopInAir : public ForkSetEndState {
    SEAD_RTTI_OVERRIDE(ForkHopInAir, ForkSetEndState)
public:
    explicit ForkHopInAir(const InitArg& arg);
    ~ForkHopInAir() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x30
    const float* mHopHeight_s{};
};

}  // namespace uking::action
