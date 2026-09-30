#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionEquipedOptionalWeaponAction.h"

namespace uking::action {

class EquipedQuiver : public ksys::game::EquipedOptionalWeaponAction {
    SEAD_RTTI_OVERRIDE(EquipedQuiver, ksys::game::EquipedOptionalWeaponAction)
public:
    explicit EquipedQuiver(const InitArg& arg);
    ~EquipedQuiver() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
    void calc_() override;
};

}  // namespace uking::action
