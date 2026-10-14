#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class XLinkEventFadeAction : public Action {
    SEAD_RTTI_OVERRIDE(XLinkEventFadeAction, Action)
public:
    explicit XLinkEventFadeAction(const InitArg& arg);
    ~XLinkEventFadeAction() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x20
    sead::SafeString mELinkKey_d{};
    // dynamic_param at offset 0x30
    sead::SafeString mSLinkKey_d{};
};

}  // namespace ksys::act::ai
