#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActorObserve.h"

namespace uking::action {

class AreaActorObserveByActorTag : public AreaActorObserve {
    SEAD_RTTI_OVERRIDE(AreaActorObserveByActorTag, AreaActorObserve)
public:
    explicit AreaActorObserveByActorTag(const InitArg& arg);
    ~AreaActorObserveByActorTag() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace uking::action
