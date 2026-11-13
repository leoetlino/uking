#pragma once

#include "Game/Actor/Action/actionOnetimeStopBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class Notice : public OnetimeStopBase {
    SEAD_RTTI_OVERRIDE(Notice, OnetimeStopBase)
public:
    explicit Notice(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
};

}  // namespace uking::action
