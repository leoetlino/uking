#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerWakeBoardReady : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerWakeBoardReady, PlayerBase)
public:
    explicit PlayerWakeBoardReady(const InitArg& arg);
    ~PlayerWakeBoardReady() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x20
    bool* mCreateSelf_d{};
    // dynamic_param at offset 0x28
    sead::SafeString mUniqueName_d{};
};

}  // namespace uking::action
