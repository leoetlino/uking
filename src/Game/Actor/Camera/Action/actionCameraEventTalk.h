#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventTalk : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventTalk, CameraEventDefaultBase)
public:
    explicit CameraEventTalk(const InitArg& arg);
    ~CameraEventTalk() override;

protected:
};

}  // namespace uking::action
