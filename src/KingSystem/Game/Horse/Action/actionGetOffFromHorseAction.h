#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::game {

class GetOffFromHorseAction : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(GetOffFromHorseAction, ksys::act::ai::Action)
public:
    explicit GetOffFromHorseAction(const InitArg& arg);
    ~GetOffFromHorseAction() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x20
    bool* mClearDemoMemberIfNotOwned_d{};
};

}  // namespace ksys::game
