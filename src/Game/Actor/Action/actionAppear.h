#pragma once

#include "Game/Actor/Action/actionOnetimeStopBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class Appear : public OnetimeStopBase {
    SEAD_RTTI_OVERRIDE(Appear, OnetimeStopBase)
public:
    explicit Appear(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
};

}  // namespace uking::action
