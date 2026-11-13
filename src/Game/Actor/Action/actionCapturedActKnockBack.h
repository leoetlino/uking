#pragma once

#include "Game/Actor/Action/actionKnockBackNoRotBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CapturedActKnockBack : public KnockBackNoRotBase {
    SEAD_RTTI_OVERRIDE(CapturedActKnockBack, KnockBackNoRotBase)
public:
    explicit CapturedActKnockBack(const InitArg& arg);
    ~CapturedActKnockBack() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
