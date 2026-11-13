#pragma once

#include "Game/Actor/Action/actionKnockBackNoRotBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class GanonSmallDamage : public KnockBackNoRotBase {
    SEAD_RTTI_OVERRIDE(GanonSmallDamage, KnockBackNoRotBase)
public:
    explicit GanonSmallDamage(const InitArg& arg);
    ~GanonSmallDamage() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x90
    sead::SafeString mUpAS_s{};
    // static_param at offset 0xa0
    sead::SafeString mAS_s{};
};

}  // namespace uking::action
