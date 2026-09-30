#include "KingSystem/Game/Event/Action/actionEventIncreasePorchItemAction.h"

namespace ksys::game {

EventIncreasePorchItemAction::EventIncreasePorchItemAction(const InitArg& arg)
    : ksys::act::ai::Action(arg) {}

EventIncreasePorchItemAction::~EventIncreasePorchItemAction() = default;

void EventIncreasePorchItemAction::loadParams_() {
    getDynamicParam(&mValue_d, "Value");
    getDynamicParam(&mPorchItemName_d, "PorchItemName");
}

}  // namespace ksys::game
