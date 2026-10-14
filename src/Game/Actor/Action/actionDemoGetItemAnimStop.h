#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/ActorSystem/actionDemoGetItem.h"

namespace uking::action {

class DemoGetItemAnimStop : public ksys::act::ai::DemoGetItem {
    SEAD_RTTI_OVERRIDE(DemoGetItemAnimStop, ksys::act::ai::DemoGetItem)
public:
    explicit DemoGetItemAnimStop(const InitArg& arg);
    ~DemoGetItemAnimStop() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // static_param at offset 0x20
    sead::SafeString mWaitASKeyName_s{};
};

}  // namespace uking::action
