#include "KingSystem/Game/Event/Action/actionEventIncreaseFameAction.h"

namespace ksys::game {

EventIncreaseFameAction::EventIncreaseFameAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

void EventIncreaseFameAction::loadParams_() {
    getDynamicParam(&mValue_d, "Value");
}

}  // namespace ksys::game
