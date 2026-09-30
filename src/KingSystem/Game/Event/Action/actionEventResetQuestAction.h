#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::game {

class EventResetQuestAction : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(EventResetQuestAction, ksys::act::ai::Action)
public:
    explicit EventResetQuestAction(const InitArg& arg);
    ~EventResetQuestAction() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x20
    sead::SafeString mQuestName_d{};
};

}  // namespace ksys::game
