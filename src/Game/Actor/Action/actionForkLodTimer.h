#pragma once

#include "Game/Actor/Action/actionForkSetEndState.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkLodTimer : public ForkSetEndState {
    SEAD_RTTI_OVERRIDE(ForkLodTimer, ForkSetEndState)
public:
    explicit ForkLodTimer(const InitArg& arg);
    ~ForkLodTimer() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x30
    const int* mWaitFrame_s{};
};

}  // namespace uking::action
