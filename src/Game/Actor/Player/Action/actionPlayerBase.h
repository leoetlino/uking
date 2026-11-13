#pragma once

#include "Game/Actor/Action/actionActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerBase : public ActionEx {
    SEAD_RTTI_OVERRIDE(PlayerBase, ActionEx)
public:
    explicit PlayerBase(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
