#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/Game/Horse/AI/aiRideHorseNonPlayer.h"

namespace uking::ai {

class EnemyHorseRide : public ksys::game::RideHorseNonPlayer {
    SEAD_RTTI_OVERRIDE(EnemyHorseRide, ksys::game::RideHorseNonPlayer)
public:
    explicit EnemyHorseRide(const InitArg& arg);
    ~EnemyHorseRide() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    // static_param at offset 0xe0
    const int* mUpperBodyASSlot_s{};
    // static_param at offset 0xe8
    const int* mLowerBodyASSlot_s{};
};

}  // namespace uking::ai
