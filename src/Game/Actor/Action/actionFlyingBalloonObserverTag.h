#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaObserveActorAction.h"

namespace uking::action {

class FlyingBalloonObserverTag : public AreaObserveActorAction {
    SEAD_RTTI_OVERRIDE(FlyingBalloonObserverTag, AreaObserveActorAction)
public:
    explicit FlyingBalloonObserverTag(const InitArg& arg);
    ~FlyingBalloonObserverTag() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
