#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventMove : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventMove, CameraEventDefaultBase)
public:
    explicit CameraEventMove(const InitArg& arg);
    ~CameraEventMove() override;

protected:
};

}  // namespace uking::action
