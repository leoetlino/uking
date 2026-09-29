#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class IdleAction : public Action {
    SEAD_RTTI_OVERRIDE(IdleAction, Action)
public:
    explicit IdleAction(const InitArg& arg);
    ~IdleAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    bool* mDisablePhysics_d{};
};

}  // namespace ksys::act::ai
