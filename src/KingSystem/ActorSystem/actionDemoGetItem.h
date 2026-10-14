#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class DemoGetItem : public Action {
    SEAD_RTTI_OVERRIDE(DemoGetItem, Action)
public:
    explicit DemoGetItem(const InitArg& arg);
    ~DemoGetItem() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
};

}  // namespace ksys::act::ai
