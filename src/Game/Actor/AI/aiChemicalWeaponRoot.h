#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/Game/AI/aiWeaponRootAI.h"

namespace uking::ai {

class ChemicalWeaponRoot : public ksys::game::WeaponRootAI {
    SEAD_RTTI_OVERRIDE(ChemicalWeaponRoot, ksys::game::WeaponRootAI)
public:
    explicit ChemicalWeaponRoot(const InitArg& arg);
    ~ChemicalWeaponRoot() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
};

}  // namespace uking::ai
