#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionBindAction.h"

namespace uking::action {

class BowArrowHold : public ksys::game::BindAction {
    SEAD_RTTI_OVERRIDE(BowArrowHold, ksys::game::BindAction)
public:
    explicit BowArrowHold(const InitArg& arg);

protected:
};

}  // namespace uking::action
