#pragma once

#include "Game/Actor/Camera/Action/actionCameraEventDefaultBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEventMultiTalk : public CameraEventDefaultBase {
    SEAD_RTTI_OVERRIDE(CameraEventMultiTalk, CameraEventDefaultBase)
public:
    explicit CameraEventMultiTalk(const InitArg& arg);
    ~CameraEventMultiTalk() override;

protected:
};

}  // namespace uking::action
