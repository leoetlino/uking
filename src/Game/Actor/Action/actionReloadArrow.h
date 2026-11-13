#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ReloadArrow : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(ReloadArrow, act::ActionEx)
public:
    explicit ReloadArrow(const InitArg& arg);
    ~ReloadArrow() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
