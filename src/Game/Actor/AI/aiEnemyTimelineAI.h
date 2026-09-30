#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/Game/AI/aiTimelineAI.h"

namespace uking::ai {

class EnemyTimelineAI : public ksys::game::TimelineAI {
    SEAD_RTTI_OVERRIDE(EnemyTimelineAI, ksys::game::TimelineAI)
public:
    explicit EnemyTimelineAI(const InitArg& arg);
    ~EnemyTimelineAI() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    // dynamic_param at offset 0x40
    sead::Vector3f* mCentralPos_d{};
};

}  // namespace uking::ai
