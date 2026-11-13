#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ShutterCloseWait : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(ShutterCloseWait, act::ActionEx)
public:
    explicit ShutterCloseWait(const InitArg& arg);
    ~ShutterCloseWait() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    sead::SafeString mASName_s{};
};

}  // namespace uking::action
