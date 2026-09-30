#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionEquipedAction.h"

namespace uking::action {

class EquipedChemicalWeapon : public EquipedAction {
    SEAD_RTTI_OVERRIDE(EquipedChemicalWeapon, EquipedAction)
public:
    explicit EquipedChemicalWeapon(const InitArg& arg);
    ~EquipedChemicalWeapon() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
    void calc_() override;
};

}  // namespace uking::action
