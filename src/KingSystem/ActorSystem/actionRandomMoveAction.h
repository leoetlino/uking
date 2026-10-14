#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class RandomMoveAction : public Action {
    SEAD_RTTI_OVERRIDE(RandomMoveAction, Action)
public:
    explicit RandomMoveAction(const InitArg& arg);
    ~RandomMoveAction() override;

    void enter_(InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x20
    const bool* mIsSuccessWhenGoalReached_s{};
};

}  // namespace ksys::act::ai
