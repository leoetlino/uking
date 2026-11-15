#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventTurn : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventTurn, CameraEventDefaultBase)
public:
    explicit CameraEventTurn(const InitArg& arg);
    ~CameraEventTurn() override;

protected:
};

}  // namespace uking::action
