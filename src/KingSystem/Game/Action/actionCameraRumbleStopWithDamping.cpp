#include "KingSystem/Game/Action/actionCameraRumbleStopWithDamping.h"

namespace ksys::game {

CameraRumbleStopWithDamping::CameraRumbleStopWithDamping(const InitArg& arg)
    : ksys::act::ai::Action(arg) {}

void CameraRumbleStopWithDamping::loadParams_() {
    getDynamicParam_2(&mDampingTime_d, "DampingTime");
    getAITreeVariable(&mCamVibId_a, "CamVibId");
}

}  // namespace ksys::game
