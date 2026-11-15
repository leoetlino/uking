#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventPolarCoord : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventPolarCoord, CameraEventDefaultBase)
public:
    explicit CameraEventPolarCoord(const InitArg& arg);

protected:
};

}  // namespace uking::action
