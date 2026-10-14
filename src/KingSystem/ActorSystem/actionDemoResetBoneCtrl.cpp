#include "KingSystem/ActorSystem/actionDemoResetBoneCtrl.h"

namespace ksys::act::ai {

DemoResetBoneCtrl::DemoResetBoneCtrl(const InitArg& arg) : Action(arg) {}

DemoResetBoneCtrl::~DemoResetBoneCtrl() = default;

bool DemoResetBoneCtrl::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void DemoResetBoneCtrl::loadParams_() {
    getDynamicParam(&mResetTarget_d, "ResetTarget");
}

}  // namespace ksys::act::ai
