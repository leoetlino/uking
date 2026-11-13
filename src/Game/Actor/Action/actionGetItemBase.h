#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class GetItemBase : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(GetItemBase, ksys::act::ai::Action)
public:
    explicit GetItemBase(const InitArg& arg);

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
