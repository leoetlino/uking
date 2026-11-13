#pragma once

#include "Game/Actor/Action/actionOnetimeStopBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class DisappearAndEscapeBase : public OnetimeStopBase {
    SEAD_RTTI_OVERRIDE(DisappearAndEscapeBase, OnetimeStopBase)
public:
    explicit DisappearAndEscapeBase(const InitArg& arg);
    ~DisappearAndEscapeBase() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
