#pragma once

#include "Game/Actor/Action/actionForkSetEndState.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkEndByPartsActorEnd : public ForkSetEndState {
    SEAD_RTTI_OVERRIDE(ForkEndByPartsActorEnd, ForkSetEndState)
public:
    explicit ForkEndByPartsActorEnd(const InitArg& arg);
    ~ForkEndByPartsActorEnd() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x30
    sead::SafeString mPartsKey_s{};
};

}  // namespace uking::action
