#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerBase : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(PlayerBase, act::ActionEx)
public:
    explicit PlayerBase(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
