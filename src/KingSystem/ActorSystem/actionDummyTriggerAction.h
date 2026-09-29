#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class DummyTriggerAction : public Action {
    SEAD_RTTI_OVERRIDE(DummyTriggerAction, Action)
public:
    explicit DummyTriggerAction(const InitArg& arg);
    ~DummyTriggerAction() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
};

}  // namespace ksys::act::ai
