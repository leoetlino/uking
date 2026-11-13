#pragma once

#include "Game/Actor/Action/actionBackStepFromTarget.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class BackStep : public BackStepFromTarget {
    SEAD_RTTI_OVERRIDE(BackStep, BackStepFromTarget)
public:
    explicit BackStep(const InitArg& arg);

protected:
};

}  // namespace uking::action
