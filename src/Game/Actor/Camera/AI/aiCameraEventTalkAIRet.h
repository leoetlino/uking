#pragma once

#include "Game/Actor/Camera/AI/aiCameraEventTalkAIBase.h"
#include "KingSystem/ActorSystem/actAiAi.h"

namespace uking::ai {

class CameraEventTalkAIRet : public CameraEventTalkAIBase {
    SEAD_RTTI_OVERRIDE(CameraEventTalkAIRet, CameraEventTalkAIBase)
public:
    explicit CameraEventTalkAIRet(const InitArg& arg);

protected:
};

}  // namespace uking::ai
