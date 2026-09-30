#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Horse/Action/actionHorseReinsDefaultAction.h"

namespace ksys::game {

class HorseReinsBindAction : public HorseReinsDefaultAction {
    SEAD_RTTI_OVERRIDE(HorseReinsBindAction, HorseReinsDefaultAction)
public:
    explicit HorseReinsBindAction(const InitArg& arg);
    ~HorseReinsBindAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0xf30
    bool* mIsLeftBind_d{};
    // dynamic_param at offset 0xf38
    bool* mIsRightBind_d{};
    // dynamic_param at offset 0xf40
    ksys::act::BaseProcLink* mRider_d{};
    // dynamic_param at offset 0xf48
    ksys::act::BaseProcLink* mHorse_d{};
};

}  // namespace ksys::game
