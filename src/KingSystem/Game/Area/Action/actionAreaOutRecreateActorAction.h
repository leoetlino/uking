#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace uking::action {

class AreaOutRecreateActorAction : public AreaActionBase {
    SEAD_RTTI_OVERRIDE(AreaOutRecreateActorAction, AreaActionBase)
public:
    explicit AreaOutRecreateActorAction(const InitArg& arg);
    ~AreaOutRecreateActorAction() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace uking::action
