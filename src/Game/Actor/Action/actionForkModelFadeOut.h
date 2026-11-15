#pragma once

#include "Game/Actor/Action/actionForkSetEndState.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkModelFadeOut : public ForkSetEndState {
    SEAD_RTTI_OVERRIDE(ForkModelFadeOut, ForkSetEndState)
public:
    explicit ForkModelFadeOut(const InitArg& arg);
    ~ForkModelFadeOut() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
