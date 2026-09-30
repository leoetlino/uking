#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaObserveActorAction.h"

namespace uking::action {

class CallOvserveActorTag : public ksys::game::AreaObserveActorAction {
    SEAD_RTTI_OVERRIDE(CallOvserveActorTag, ksys::game::AreaObserveActorAction)
public:
    explicit CallOvserveActorTag(const InitArg& arg);
    ~CallOvserveActorTag() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
