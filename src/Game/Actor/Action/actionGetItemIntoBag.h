#pragma once

#include "Game/Actor/Action/actionGetItemBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class GetItemIntoBag : public GetItemBase {
    SEAD_RTTI_OVERRIDE(GetItemIntoBag, GetItemBase)
public:
    explicit GetItemIntoBag(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
