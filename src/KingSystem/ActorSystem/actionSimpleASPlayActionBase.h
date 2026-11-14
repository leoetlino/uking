#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::act::ai {

class SimpleASPlayActionBase : public Action {
    SEAD_RTTI_OVERRIDE(SimpleASPlayActionBase, Action)
public:
    explicit SimpleASPlayActionBase(const InitArg& arg);
    ~SimpleASPlayActionBase() override;

    bool init_(sead::Heap* heap) override;
    void enter_(InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace ksys::act::ai
