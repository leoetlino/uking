#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace uking::action {

class SetComebackPosition : public AreaActionBase {
    SEAD_RTTI_OVERRIDE(SetComebackPosition, AreaActionBase)
public:
    explicit SetComebackPosition(const InitArg& arg);
    ~SetComebackPosition() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // map_unit_param at offset 0x38
    const float* mAngleY_m{};
};

}  // namespace uking::action
