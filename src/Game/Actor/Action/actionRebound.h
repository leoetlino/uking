#pragma once

#include "Game/Actor/Action/actionOnetimeStopBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class Rebound : public OnetimeStopBase {
    SEAD_RTTI_OVERRIDE(Rebound, OnetimeStopBase)
public:
    explicit Rebound(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
};

}  // namespace uking::action
