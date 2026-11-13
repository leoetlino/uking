#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace ksys::game {

class AreaObserveActorBase : public AreaActionBase {
    SEAD_RTTI_OVERRIDE(AreaObserveActorBase, AreaActionBase)
public:
    explicit AreaObserveActorBase(const InitArg& arg);
    ~AreaObserveActorBase() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // map_unit_param at offset 0x38
    const int* mCount_m{};
    // map_unit_param at offset 0x40
    const bool* mIsSendMessage_m{};
    // map_unit_param at offset 0x48
    const bool* mDefaultBasicSignal_m{};
};

}  // namespace ksys::game
