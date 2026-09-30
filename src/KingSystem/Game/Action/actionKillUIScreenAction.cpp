#include "KingSystem/Game/Action/actionKillUIScreenAction.h"

namespace ksys::game {

KillUIScreenAction::KillUIScreenAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

KillUIScreenAction::~KillUIScreenAction() = default;

bool KillUIScreenAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void KillUIScreenAction::loadParams_() {
    getDynamicParam(&mScreenName_d, "ScreenName");
}

}  // namespace ksys::game
