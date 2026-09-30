#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionBindAction.h"

namespace uking::action {

class EquipedOptionalWeaponAction : public BindAction {
    SEAD_RTTI_OVERRIDE(EquipedOptionalWeaponAction, BindAction)
public:
    explicit EquipedOptionalWeaponAction(const InitArg& arg);

protected:
};

}  // namespace uking::action
