#include "KingSystem/Game/Event/Action/actionEventOnWaitRevivalAction.h"

namespace ksys::game {

EventOnWaitRevivalAction::EventOnWaitRevivalAction(const InitArg& arg)
    : ksys::act::ai::Action(arg) {}

EventOnWaitRevivalAction::~EventOnWaitRevivalAction() = default;

bool EventOnWaitRevivalAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void EventOnWaitRevivalAction::loadParams_() {}

}  // namespace ksys::game
