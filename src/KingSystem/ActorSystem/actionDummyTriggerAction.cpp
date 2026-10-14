#include "KingSystem/ActorSystem/actionDummyTriggerAction.h"

namespace ksys::act::ai {

DummyTriggerAction::DummyTriggerAction(const InitArg& arg) : Action(arg) {}

DummyTriggerAction::~DummyTriggerAction() = default;

bool DummyTriggerAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void DummyTriggerAction::loadParams_() {}

}  // namespace ksys::act::ai
