#pragma once

#include "Game/Actor/Action/actionKnockBackShockWithAS.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class SubAnmKnockBackShock : public KnockBackShockWithAS {
    SEAD_RTTI_OVERRIDE(SubAnmKnockBackShock, KnockBackShockWithAS)
public:
    explicit SubAnmKnockBackShock(const InitArg& arg);
    ~SubAnmKnockBackShock() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x48
    const int* mSubASSlot_s{};
    // static_param at offset 0x50
    sead::SafeString mSubAS_s{};
    // static_param at offset 0x60
    sead::SafeString mLeaveSubAS_s{};
};

}  // namespace uking::action
