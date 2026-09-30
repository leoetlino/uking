#include "KingSystem/Game/Event/Action/actionEventSetGameDataIntAction.h"

namespace ksys::game {

EventSetGameDataIntAction::EventSetGameDataIntAction(const InitArg& arg)
    : ksys::act::ai::Action(arg) {}

EventSetGameDataIntAction::~EventSetGameDataIntAction() = default;

bool EventSetGameDataIntAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void EventSetGameDataIntAction::loadParams_() {
    getDynamicParam(&mValue_d, "Value");
    getDynamicParam(&mGameDataIntName_d, "GameDataIntName");
}

}  // namespace ksys::game
