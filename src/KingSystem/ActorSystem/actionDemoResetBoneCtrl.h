#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class DemoResetBoneCtrl : public Action {
    SEAD_RTTI_OVERRIDE(DemoResetBoneCtrl, Action)
public:
    explicit DemoResetBoneCtrl(const InitArg& arg);
    ~DemoResetBoneCtrl() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x20
    int* mResetTarget_d{};
};

}  // namespace ksys::act::ai
