#include "KingSystem/ActorSystem/actionXLinkEventFadeAction.h"

namespace ksys::act::ai {

XLinkEventFadeAction::XLinkEventFadeAction(const InitArg& arg) : Action(arg) {}

XLinkEventFadeAction::~XLinkEventFadeAction() = default;

bool XLinkEventFadeAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void XLinkEventFadeAction::loadParams_() {
    getDynamicParam(&mELinkKey_d, "ELinkKey");
    getDynamicParam(&mSLinkKey_d, "SLinkKey");
}

}  // namespace ksys::act::ai
