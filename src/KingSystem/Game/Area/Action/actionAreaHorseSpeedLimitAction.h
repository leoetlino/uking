#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace uking::action {

class AreaHorseSpeedLimitAction : public AreaActionBase {
    SEAD_RTTI_OVERRIDE(AreaHorseSpeedLimitAction, AreaActionBase)
public:
    explicit AreaHorseSpeedLimitAction(const InitArg& arg);
    ~AreaHorseSpeedLimitAction() override;

    bool init_(sead::Heap* heap) override;

protected:
};

}  // namespace uking::action
