#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace uking::action {

class AreaBottomTag : public AreaActionBase {
    SEAD_RTTI_OVERRIDE(AreaBottomTag, AreaActionBase)
public:
    explicit AreaBottomTag(const InitArg& arg);
    ~AreaBottomTag() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
