#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/Game/AI/aiWeaponRootAI.h"

namespace uking::ai {

class ChemicalWeaponRoot : public WeaponRootAI {
    SEAD_RTTI_OVERRIDE(ChemicalWeaponRoot, WeaponRootAI)
public:
    explicit ChemicalWeaponRoot(const InitArg& arg);
    ~ChemicalWeaponRoot() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
};

}  // namespace uking::ai
