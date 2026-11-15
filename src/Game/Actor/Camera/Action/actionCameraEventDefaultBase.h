#pragma once

#include "Game/Actor/Camera/Action/actionCameraAction.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventDefaultBase : public CameraAction {
    SEAD_RTTI_OVERRIDE(CameraEventDefaultBase, CameraAction)
public:
    explicit CameraEventDefaultBase(const InitArg& arg);

protected:
};

}  // namespace uking::action
