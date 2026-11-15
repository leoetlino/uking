#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventIdling : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventIdling, CameraEventDefaultBase)
public:
    explicit CameraEventIdling(const InitArg& arg);

protected:
};

}  // namespace uking::action
