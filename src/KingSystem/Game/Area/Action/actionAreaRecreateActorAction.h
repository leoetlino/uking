#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace ksys::game {

class AreaRecreateActorAction : public AreaActionBase {
    SEAD_RTTI_OVERRIDE(AreaRecreateActorAction, AreaActionBase)
public:
    explicit AreaRecreateActorAction(const InitArg& arg);
    ~AreaRecreateActorAction() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace ksys::game
