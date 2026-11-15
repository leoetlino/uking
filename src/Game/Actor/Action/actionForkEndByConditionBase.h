#pragma once

#include "Game/Actor/Action/actionForkSetEndState.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkEndByConditionBase : public ForkSetEndState {
    SEAD_RTTI_OVERRIDE(ForkEndByConditionBase, ForkSetEndState)
public:
    explicit ForkEndByConditionBase(const InitArg& arg);
    ~ForkEndByConditionBase() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
