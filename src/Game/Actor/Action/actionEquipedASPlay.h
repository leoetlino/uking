#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionEquipedAction.h"

namespace uking::action {

class EquipedASPlay : public ksys::game::EquipedAction {
    SEAD_RTTI_OVERRIDE(EquipedASPlay, ksys::game::EquipedAction)
public:
    explicit EquipedASPlay(const InitArg& arg);
    ~EquipedASPlay() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x40
    sead::SafeString mAS_s{};
};

}  // namespace uking::action
