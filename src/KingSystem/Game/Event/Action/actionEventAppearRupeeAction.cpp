#include "KingSystem/Game/Event/Action/actionEventAppearRupeeAction.h"

namespace ksys::game {

EventAppearRupeeAction::EventAppearRupeeAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

void EventAppearRupeeAction::loadParams_() {
    getDynamicParam(&mIsVisible_d, "IsVisible");
}

}  // namespace ksys::game
