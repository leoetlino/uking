#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/ActorSystem/actionTurnToActorBase.h"

namespace ksys::act::ai {

class TurnToActor : public TurnToActorBase {
    SEAD_RTTI_OVERRIDE(TurnToActor, TurnToActorBase)
public:
    explicit TurnToActor(const InitArg& arg);
    ~TurnToActor() override;

    bool init_(sead::Heap* heap) override;
    void enter_(InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    int* mASSlot_d{};
    // dynamic_param at offset 0x28
    int* mSequenceBank_d{};
    // dynamic_param at offset 0x30
    bool* mIsIgnoreSame_d{};
    // dynamic_param at offset 0x38
    bool* mIsChangeable_d{};
    // dynamic_param at offset 0x40
    sead::SafeString mASName_d{};
    // dynamic_param at offset 0x50
    sead::SafeString mDemoASName_d{};
};

}  // namespace ksys::act::ai
