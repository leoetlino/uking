#pragma once

#include "Game/Actor/Action/actionKnockBackNoRotBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class AnmDamage : public KnockBackNoRotBase {
    SEAD_RTTI_OVERRIDE(AnmDamage, KnockBackNoRotBase)
public:
    explicit AnmDamage(const InitArg& arg);
    ~AnmDamage() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x90
    sead::SafeString mAS_s{};
};

}  // namespace uking::action
