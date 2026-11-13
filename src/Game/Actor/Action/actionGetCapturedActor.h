#pragma once

#include "Game/Actor/Action/actionGetItemBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class GetCapturedActor : public GetItemBase {
    SEAD_RTTI_OVERRIDE(GetCapturedActor, GetItemBase)
public:
    explicit GetCapturedActor(const InitArg& arg);
    ~GetCapturedActor() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
