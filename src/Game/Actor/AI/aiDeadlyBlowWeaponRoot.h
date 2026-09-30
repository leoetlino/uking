#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/Game/AI/aiWeaponRootAI.h"

namespace uking::ai {

class DeadlyBlowWeaponRoot : public ksys::game::WeaponRootAI {
    SEAD_RTTI_OVERRIDE(DeadlyBlowWeaponRoot, ksys::game::WeaponRootAI)
public:
    explicit DeadlyBlowWeaponRoot(const InitArg& arg);
    ~DeadlyBlowWeaponRoot() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
};

}  // namespace uking::ai
