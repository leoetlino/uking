#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/ActorObserverBase.h"

namespace ksys::game {

class AreaActionBase : public ksys::act::ai::Action, public ActorObserver {
    SEAD_RTTI_OVERRIDE(AreaActionBase, ksys::act::ai::Action)
public:
    explicit AreaActionBase(const InitArg& arg);
    ~AreaActionBase() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    bool handleMessage_(const Message& message) override;

protected:
    void calc_() override;
};
KSYS_CHECK_SIZE_NX150(AreaActionBase, 0x38);

}  // namespace ksys::game
