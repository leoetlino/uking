#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActorObserve.h"

namespace uking::action {

class AreaObserveActorAction : public AreaActorObserve {
    SEAD_RTTI_OVERRIDE(AreaObserveActorAction, AreaActorObserve)
public:
    explicit AreaObserveActorAction(const InitArg& arg);
    ~AreaObserveActorAction() override;

protected:
};

}  // namespace uking::action
