#pragma once

#include "Game/Actor/Action/actionSimpleKnockBackShock.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class KnockBackShockWithAS : public SimpleKnockBackShock {
    SEAD_RTTI_OVERRIDE(KnockBackShockWithAS, SimpleKnockBackShock)
public:
    explicit KnockBackShockWithAS(const InitArg& arg);
    ~KnockBackShockWithAS() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x38
    sead::SafeString mASName_s{};
};

}  // namespace uking::action
