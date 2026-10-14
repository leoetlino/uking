#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class TurnToActorBase : public Action {
    SEAD_RTTI_OVERRIDE(TurnToActorBase, Action)
public:
    explicit TurnToActorBase(const InitArg& arg);
    ~TurnToActorBase() override;

    bool init_(sead::Heap* heap) override;
    void enter_(InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace ksys::act::ai
