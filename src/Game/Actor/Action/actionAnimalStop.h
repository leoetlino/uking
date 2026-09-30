#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Horse/Action/actionHorseWaitAction.h"

namespace uking::action {

class AnimalStop : public ksys::game::HorseWaitAction {
    SEAD_RTTI_OVERRIDE(AnimalStop, ksys::game::HorseWaitAction)
public:
    explicit AnimalStop(const InitArg& arg);
    ~AnimalStop() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x60
    const bool* mIsFixAxisY_s{};
};

}  // namespace uking::action
