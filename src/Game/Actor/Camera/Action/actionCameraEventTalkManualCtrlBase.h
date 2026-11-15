#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventTalkManualCtrlBase : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventTalkManualCtrlBase, CameraEventDefaultBase)
public:
    explicit CameraEventTalkManualCtrlBase(const InitArg& arg);
    ~CameraEventTalkManualCtrlBase() override;

protected:
};

}  // namespace uking::action
