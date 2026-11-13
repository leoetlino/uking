#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::game {

class HorseSwimBase : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(HorseSwimBase, ksys::act::ai::Action)
public:
    explicit HorseSwimBase(const InitArg& arg);
    ~HorseSwimBase() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace ksys::game
