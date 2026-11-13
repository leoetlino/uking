#pragma once

#include "Game/Actor/Action/actionRagdollGetUpBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class SilentKilled : public RagdollGetUpBase {
    SEAD_RTTI_OVERRIDE(SilentKilled, RagdollGetUpBase)
public:
    explicit SilentKilled(const InitArg& arg);
    ~SilentKilled() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
