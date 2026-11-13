#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class BombExplode : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(BombExplode, act::ActionEx)
public:
    explicit BombExplode(const InitArg& arg);
    ~BombExplode() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
