#include "KingSystem/Game/Event/Action/actionEventRollbackQuestAction.h"

namespace ksys::game {

EventRollbackQuestAction::EventRollbackQuestAction(const InitArg& arg)
    : ksys::act::ai::Action(arg) {}

EventRollbackQuestAction::~EventRollbackQuestAction() = default;

bool EventRollbackQuestAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void EventRollbackQuestAction::loadParams_() {
    getDynamicParam(&mQuestName_d, "QuestName");
    getDynamicParam(&mStepName_d, "StepName");
}

}  // namespace ksys::game
