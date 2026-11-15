#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventLookBase : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventLookBase, CameraEventDefaultBase)
public:
    explicit CameraEventLookBase(const InitArg& arg);
    ~CameraEventLookBase() override;

protected:
};

}  // namespace uking::action
