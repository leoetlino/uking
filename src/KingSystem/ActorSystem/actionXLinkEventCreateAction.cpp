#include "KingSystem/ActorSystem/actionXLinkEventCreateAction.h"

namespace ksys::act::ai {

XLinkEventCreateAction::XLinkEventCreateAction(const InitArg& arg) : Action(arg) {}

XLinkEventCreateAction::~XLinkEventCreateAction() = default;

bool XLinkEventCreateAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void XLinkEventCreateAction::loadParams_() {
    getDynamicParam(&mIsTargetDemoSLinkUser_d, "IsTargetDemoSLinkUser");
    getDynamicParam(&mELinkKey_d, "ELinkKey");
    getDynamicParam(&mSLinkKey_d, "SLinkKey");
}

}  // namespace ksys::act::ai
