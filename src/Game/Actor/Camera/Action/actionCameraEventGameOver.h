#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventGameOver : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventGameOver, CameraEventDefaultBase)
public:
    explicit CameraEventGameOver(const InitArg& arg);
    ~CameraEventGameOver() override;

protected:
};

}  // namespace uking::action
