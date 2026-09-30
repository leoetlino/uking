#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace uking::action {

class ForbidComeback : public ksys::game::AreaActionBase {
    SEAD_RTTI_OVERRIDE(ForbidComeback, ksys::game::AreaActionBase)
public:
    explicit ForbidComeback(const InitArg& arg);
    ~ForbidComeback() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
