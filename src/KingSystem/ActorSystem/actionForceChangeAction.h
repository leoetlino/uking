#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class ForceChangeAction : public Action {
    SEAD_RTTI_OVERRIDE(ForceChangeAction, Action)
public:
    explicit ForceChangeAction(const InitArg& arg);
    ~ForceChangeAction() override;

    void enter_(InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    sead::SafeString mTree_s{};
};

}  // namespace ksys::act::ai
