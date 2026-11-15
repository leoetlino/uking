#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ForkSetEndState : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(ForkSetEndState, ksys::act::ai::Action)
public:
    explicit ForkSetEndState(const InitArg& arg);
    ~ForkSetEndState() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void setEndState();

    void calc_() override;

    // static_param at offset 0x20
    const int* mEndState_s{};
    // static_param at offset 0x28
    const bool* mIsChangeable_s{};
};

}  // namespace uking::action
