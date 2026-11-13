#pragma once

#include "Game/Actor/Action/actionKnockBackHitImpactForce.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class KnockBackNoRotBase : public KnockBackHitImpactForce {
    SEAD_RTTI_OVERRIDE(KnockBackNoRotBase, KnockBackHitImpactForce)
public:
    explicit KnockBackNoRotBase(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
    void calc_() override;
};

}  // namespace uking::action
