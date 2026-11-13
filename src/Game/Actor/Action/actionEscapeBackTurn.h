#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class EscapeBackTurn : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(EscapeBackTurn, act::ActionEx)
public:
    explicit EscapeBackTurn(const InitArg& arg);
    ~EscapeBackTurn() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
