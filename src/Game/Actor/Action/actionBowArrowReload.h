#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionBindAction.h"

namespace uking::action {

class BowArrowReload : public ksys::game::BindAction {
    SEAD_RTTI_OVERRIDE(BowArrowReload, ksys::game::BindAction)
public:
    explicit BowArrowReload(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
    void calc_() override;
};

}  // namespace uking::action
