#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventAnimBase : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventAnimBase, CameraEventDefaultBase)
public:
    explicit CameraEventAnimBase(const InitArg& arg);
    ~CameraEventAnimBase() override;

protected:
};

}  // namespace uking::action
