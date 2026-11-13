#pragma once

#include "Game/Actor/Action/actionKnockBackNoRotBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class SmallDamage : public KnockBackNoRotBase {
    SEAD_RTTI_OVERRIDE(SmallDamage, KnockBackNoRotBase)
public:
    explicit SmallDamage(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
};

}  // namespace uking::action
