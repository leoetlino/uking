#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaObserveActorBase.h"

namespace uking::action {

class AreaActorObserveByGroup : public ksys::game::AreaObserveActorBase {
    SEAD_RTTI_OVERRIDE(AreaActorObserveByGroup, ksys::game::AreaObserveActorBase)
public:
    explicit AreaActorObserveByGroup(const InitArg& arg);
    ~AreaActorObserveByGroup() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace uking::action
