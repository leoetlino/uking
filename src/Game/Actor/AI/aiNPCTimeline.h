#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"
#include "KingSystem/Game/AI/aiTimelineAI.h"

namespace uking::ai {

class NPCTimeline : public ksys::game::TimelineAI {
    SEAD_RTTI_OVERRIDE(NPCTimeline, ksys::game::TimelineAI)
public:
    explicit NPCTimeline(const InitArg& arg);
    ~NPCTimeline() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
};

}  // namespace uking::ai
