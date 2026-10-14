#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class UpdateDataByGetDemoAction : public Action {
    SEAD_RTTI_OVERRIDE(UpdateDataByGetDemoAction, Action)
public:
    explicit UpdateDataByGetDemoAction(const InitArg& arg);
    ~UpdateDataByGetDemoAction() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
};

}  // namespace ksys::act::ai
