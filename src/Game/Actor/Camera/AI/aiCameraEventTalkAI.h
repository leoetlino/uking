#pragma once

#include "Game/Actor/Camera/AI/aiCameraEventTalkAIBase.h"
#include "KingSystem/ActorSystem/actAiAi.h"

namespace uking::ai {

class CameraEventTalkAI : public CameraEventTalkAIBase {
    SEAD_RTTI_OVERRIDE(CameraEventTalkAI, CameraEventTalkAIBase)
public:
    explicit CameraEventTalkAI(const InitArg& arg);

protected:
};

}  // namespace uking::ai
