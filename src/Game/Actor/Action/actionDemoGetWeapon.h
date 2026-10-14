#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/ActorSystem/actionDemoGetItem.h"

namespace uking::action {

class DemoGetWeapon : public ksys::act::ai::DemoGetItem {
    SEAD_RTTI_OVERRIDE(DemoGetWeapon, ksys::act::ai::DemoGetItem)
public:
    explicit DemoGetWeapon(const InitArg& arg);
    ~DemoGetWeapon() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
};

}  // namespace uking::action
