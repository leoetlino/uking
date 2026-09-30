#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActorObserve.h"

namespace uking::action {

class AreaActorObserveByGroup : public AreaActorObserve {
    SEAD_RTTI_OVERRIDE(AreaActorObserveByGroup, AreaActorObserve)
public:
    explicit AreaActorObserveByGroup(const InitArg& arg);
    ~AreaActorObserveByGroup() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace uking::action
