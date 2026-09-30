#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/Game/Horse/AI/aiHorseRiddenByNPCBase.h"

namespace uking::ai {

class HorseRiddenByNPC : public ksys::game::HorseRiddenByNPCBase {
    SEAD_RTTI_OVERRIDE(HorseRiddenByNPC, ksys::game::HorseRiddenByNPCBase)
public:
    explicit HorseRiddenByNPC(const InitArg& arg);
    ~HorseRiddenByNPC() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    // static_param at offset 0x48
    const float* mNavMeshCharacterScaleAtPrecise_s{};
};

}  // namespace uking::ai
