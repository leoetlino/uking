#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/Game/AI/aiWeaponRootAI.h"

namespace uking::ai {

class MasterSwordRoot : public ksys::game::WeaponRootAI {
    SEAD_RTTI_OVERRIDE(MasterSwordRoot, ksys::game::WeaponRootAI)
public:
    explicit MasterSwordRoot(const InitArg& arg);
    ~MasterSwordRoot() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    // aitree_variable at offset 0xf0
    void* mMagicCreateUnit_a{};
};

}  // namespace uking::ai
