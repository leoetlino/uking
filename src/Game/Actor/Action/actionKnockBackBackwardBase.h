#pragma once

#include "Game/Actor/Action/actionKnockBackHitImpactForce.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class KnockBackBackwardBase : public KnockBackHitImpactForce {
    SEAD_RTTI_OVERRIDE(KnockBackBackwardBase, KnockBackHitImpactForce)
public:
    explicit KnockBackBackwardBase(const InitArg& arg);
    ~KnockBackBackwardBase() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
