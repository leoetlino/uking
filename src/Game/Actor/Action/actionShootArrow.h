#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class ShootArrow : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(ShootArrow, act::ActionEx)
public:
    explicit ShootArrow(const InitArg& arg);
    ~ShootArrow() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
