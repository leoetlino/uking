#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerTalk : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerTalk, PlayerBase)
public:
    explicit PlayerTalk(const InitArg& arg);
    ~PlayerTalk() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0xc0
    sead::SafeString mGreetingType_d{};
};

}  // namespace uking::action
