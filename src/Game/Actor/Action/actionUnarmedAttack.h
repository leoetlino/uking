#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class UnarmedAttack : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(UnarmedAttack, act::ActionEx)
public:
    explicit UnarmedAttack(const InitArg& arg);
    ~UnarmedAttack() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
