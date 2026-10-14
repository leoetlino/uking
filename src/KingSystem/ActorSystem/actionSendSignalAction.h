#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class SendSignalAction : public Action {
    SEAD_RTTI_OVERRIDE(SendSignalAction, Action)
public:
    explicit SendSignalAction(const InitArg& arg);
    ~SendSignalAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    int* mSignalType_d{};
    // dynamic_param at offset 0x28
    bool* mValue_d{};
};

}  // namespace ksys::act::ai
