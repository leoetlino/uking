#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaObserveActorBase.h"

namespace uking::action {

class AreaActorObserveByActorTag : public ksys::game::AreaObserveActorBase {
    SEAD_RTTI_OVERRIDE(AreaActorObserveByActorTag, ksys::game::AreaObserveActorBase)
public:
    explicit AreaActorObserveByActorTag(const InitArg& arg);
    ~AreaActorObserveByActorTag() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace uking::action
