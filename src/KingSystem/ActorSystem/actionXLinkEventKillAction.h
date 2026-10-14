#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class XLinkEventKillAction : public Action {
    SEAD_RTTI_OVERRIDE(XLinkEventKillAction, Action)
public:
    explicit XLinkEventKillAction(const InitArg& arg);
    ~XLinkEventKillAction() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x20
    sead::SafeString mELinkKey_d{};
    // dynamic_param at offset 0x30
    sead::SafeString mSLinkKey_d{};
};

}  // namespace ksys::act::ai
