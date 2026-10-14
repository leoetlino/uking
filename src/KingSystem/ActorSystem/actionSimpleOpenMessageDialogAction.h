#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class SimpleOpenMessageDialogAction : public Action {
    SEAD_RTTI_OVERRIDE(SimpleOpenMessageDialogAction, Action)
public:
    explicit SimpleOpenMessageDialogAction(const InitArg& arg);
    ~SimpleOpenMessageDialogAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    sead::SafeString mMstxt_d{};
    // dynamic_param at offset 0x30
    sead::SafeString mLabel_d{};
};

}  // namespace ksys::act::ai
