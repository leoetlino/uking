#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class DemoVisibleOff : public Action {
    SEAD_RTTI_OVERRIDE(DemoVisibleOff, Action)
public:
    explicit DemoVisibleOff(const InitArg& arg);
    ~DemoVisibleOff() override;

    void enter_(InlineParamPack* params) override;
    void leave_() override;

protected:
};

}  // namespace ksys::act::ai
