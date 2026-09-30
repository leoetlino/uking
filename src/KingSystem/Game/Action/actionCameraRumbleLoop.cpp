#include "KingSystem/Game/Action/actionCameraRumbleLoop.h"

namespace ksys::game {

CameraRumbleLoop::CameraRumbleLoop(const InitArg& arg) : ksys::act::ai::Action(arg) {}

void CameraRumbleLoop::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void CameraRumbleLoop::loadParams_() {
    getDynamicParam_2(&mPattern_d, "Pattern");
    getDynamicParam_2(&mPower_d, "Power");
    getDynamicParam_2(&mSideways_d, "Sideways");
    getAITreeVariable(&mCamVibId_a, "CamVibId");
}

}  // namespace ksys::game
