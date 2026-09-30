#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActorObserve.h"

namespace uking::action {

class AreaActorObserveByGroup : public ksys::game::AreaActorObserve {
    SEAD_RTTI_OVERRIDE(AreaActorObserveByGroup, ksys::game::AreaActorObserve)
public:
    explicit AreaActorObserveByGroup(const InitArg& arg);
    ~AreaActorObserveByGroup() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace uking::action
