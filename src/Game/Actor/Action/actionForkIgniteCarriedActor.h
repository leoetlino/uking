#pragma once

#include "Game/Actor/Action/actionForkSetEndState.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkIgniteCarriedActor : public ForkSetEndState {
    SEAD_RTTI_OVERRIDE(ForkIgniteCarriedActor, ForkSetEndState)
public:
    explicit ForkIgniteCarriedActor(const InitArg& arg);
    ~ForkIgniteCarriedActor() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
