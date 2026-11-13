#pragma once

#include "Game/Actor/Player/Action/actionPlayerBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class PlayerSubjectWait : public PlayerBase {
    SEAD_RTTI_OVERRIDE(PlayerSubjectWait, PlayerBase)
public:
    explicit PlayerSubjectWait(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
