#include "KingSystem/Game/Event/Action/actionEventResetQuestAction.h"

namespace ksys::game {

EventResetQuestAction::EventResetQuestAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

EventResetQuestAction::~EventResetQuestAction() = default;

bool EventResetQuestAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void EventResetQuestAction::loadParams_() {
    getDynamicParam(&mQuestName_d, "QuestName");
}

}  // namespace ksys::game
