#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Horse/Action/actionHorseSwimBase.h"

namespace uking::action {

class HorseSwimToTargetActor : public ksys::game::HorseSwimBase {
    SEAD_RTTI_OVERRIDE(HorseSwimToTargetActor, ksys::game::HorseSwimBase)
public:
    explicit HorseSwimToTargetActor(const InitArg& arg);
    ~HorseSwimToTargetActor() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    ksys::frm::BaseProcLink* mTargetActor_d{};
};

}  // namespace uking::action
