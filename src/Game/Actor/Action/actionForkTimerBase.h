#pragma once

#include "Game/Actor/Action/actionForkSetEndState.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkTimerBase : public ForkSetEndState {
    SEAD_RTTI_OVERRIDE(ForkTimerBase, ForkSetEndState)
public:
    explicit ForkTimerBase(const InitArg& arg);
    ~ForkTimerBase() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
