#include "KingSystem/ActorSystem/actionXLinkEventKillAction.h"

namespace ksys::act::ai {

XLinkEventKillAction::XLinkEventKillAction(const InitArg& arg) : Action(arg) {}

XLinkEventKillAction::~XLinkEventKillAction() = default;

bool XLinkEventKillAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void XLinkEventKillAction::loadParams_() {
    getDynamicParam(&mELinkKey_d, "ELinkKey");
    getDynamicParam(&mSLinkKey_d, "SLinkKey");
}

}  // namespace ksys::act::ai
