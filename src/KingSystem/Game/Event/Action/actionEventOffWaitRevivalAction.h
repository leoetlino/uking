#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::game {

class EventOffWaitRevivalAction : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(EventOffWaitRevivalAction, ksys::act::ai::Action)
public:
    explicit EventOffWaitRevivalAction(const InitArg& arg);
    ~EventOffWaitRevivalAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace ksys::game
