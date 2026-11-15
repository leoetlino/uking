#pragma once

#include "Game/Actor/Camera/AI/aiCameraEvent.h"
#include "KingSystem/ActorSystem/actAiAi.h"

namespace uking::ai {

class CameraEventTalkAIBase : public CameraEvent {
    SEAD_RTTI_OVERRIDE(CameraEventTalkAIBase, CameraEvent)
public:
    explicit CameraEventTalkAIBase(const InitArg& arg);
    ~CameraEventTalkAIBase() override;

protected:
};

}  // namespace uking::ai
