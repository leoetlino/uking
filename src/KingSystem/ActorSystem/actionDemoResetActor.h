#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class DemoResetActor : public Action {
    SEAD_RTTI_OVERRIDE(DemoResetActor, Action)
public:
    explicit DemoResetActor(const InitArg& arg);
    ~DemoResetActor() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x20
    sead::SafeString mActorName_d{};
};

}  // namespace ksys::act::ai
