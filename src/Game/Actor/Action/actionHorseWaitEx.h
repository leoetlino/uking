#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Horse/Action/actionHorseWaitAction.h"

namespace uking::action {

class HorseWaitEx : public ksys::game::HorseWaitAction {
    SEAD_RTTI_OVERRIDE(HorseWaitEx, ksys::game::HorseWaitAction)
public:
    explicit HorseWaitEx(const InitArg& arg);
    ~HorseWaitEx() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x60
    const float* mKeepFrame_s{};
};

}  // namespace uking::action
