#include "KingSystem/Game/Event/Action/actionSetQuestStepAction.h"

namespace ksys::game {

SetQuestStepAction::SetQuestStepAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

SetQuestStepAction::~SetQuestStepAction() = default;

bool SetQuestStepAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void SetQuestStepAction::loadParams_() {
    getDynamicParam(&mForceRunTelop_d, "ForceRunTelop");
    getDynamicParam(&mQuestName_d, "QuestName");
    getDynamicParam(&mStepName_d, "StepName");
}

}  // namespace ksys::game
