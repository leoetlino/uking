#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Horse/Action/actionHorseWaitAction.h"

namespace uking::action {

class HorseWaitAndLookAtNPC : public ksys::game::HorseWaitAction {
    SEAD_RTTI_OVERRIDE(HorseWaitAndLookAtNPC, ksys::game::HorseWaitAction)
public:
    explicit HorseWaitAndLookAtNPC(const InitArg& arg);
    ~HorseWaitAndLookAtNPC() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
