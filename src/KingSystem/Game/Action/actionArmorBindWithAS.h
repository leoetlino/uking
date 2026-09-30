#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionArmorBindAction.h"

namespace ksys::game {

class ArmorBindWithAS : public ArmorBindAction {
    SEAD_RTTI_OVERRIDE(ArmorBindWithAS, ArmorBindAction)
public:
    explicit ArmorBindWithAS(const InitArg& arg);
    ~ArmorBindWithAS() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x30
    sead::SafeString mASName_d{};
};

}  // namespace ksys::game
