#pragma once

#include "Game/Actor/Action/actionStopBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class OnetimeStopBase : public StopBase {
    SEAD_RTTI_OVERRIDE(OnetimeStopBase, StopBase)
public:
    explicit OnetimeStopBase(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
    void calc_() override;
};

}  // namespace uking::action
