#include "KingSystem/Game/Event/Action/actionEventFlagONAction.h"

namespace ksys::game {

EventFlagONAction::EventFlagONAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

EventFlagONAction::~EventFlagONAction() = default;

bool EventFlagONAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void EventFlagONAction::loadParams_() {
    getDynamicParam(&mFlagName_d, "FlagName");
}

}  // namespace ksys::game
