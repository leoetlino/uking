#include "KingSystem/Game/Action/actionCameraRumbleStop.h"

namespace ksys::game {

CameraRumbleStop::CameraRumbleStop(const InitArg& arg) : ksys::act::ai::Action(arg) {}

void CameraRumbleStop::loadParams_() {
    getAITreeVariable(&mCamVibId_a, "CamVibId");
}

}  // namespace ksys::game
