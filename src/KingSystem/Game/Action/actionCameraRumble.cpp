#include "KingSystem/Game/Action/actionCameraRumble.h"

namespace ksys::game {

CameraRumble::CameraRumble(const InitArg& arg) : ksys::act::ai::Action(arg) {}

void CameraRumble::loadParams_() {
    getDynamicParam_2(&mPattern_d, "Pattern");
    getDynamicParam_2(&mCount_d, "Count");
    getDynamicParam_2(&mPower_d, "Power");
    getDynamicParam_2(&mSideways_d, "Sideways");
}

}  // namespace ksys::game
