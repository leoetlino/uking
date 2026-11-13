#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaObserveActorBase.h"

namespace ksys::game {

class AreaObserveActorAction : public AreaObserveActorBase {
    SEAD_RTTI_OVERRIDE(AreaObserveActorAction, AreaObserveActorBase)
public:
    explicit AreaObserveActorAction(const InitArg& arg);
    ~AreaObserveActorAction() override;

protected:
};

}  // namespace ksys::game
