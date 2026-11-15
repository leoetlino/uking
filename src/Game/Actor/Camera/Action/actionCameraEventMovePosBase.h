#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventMovePosBase : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventMovePosBase, CameraEventDefaultBase)
public:
    explicit CameraEventMovePosBase(const InitArg& arg);
    ~CameraEventMovePosBase() override;

protected:
};

}  // namespace uking::action
