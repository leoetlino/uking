#pragma once

#include "Game/Actor/Action/actionOnetimeStopBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class Search : public OnetimeStopBase {
    SEAD_RTTI_OVERRIDE(Search, OnetimeStopBase)
public:
    explicit Search(const InitArg& arg);
    ~Search() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x30
    const float* mNoChangeTime_s{};
};

}  // namespace uking::action
