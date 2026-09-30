#include "KingSystem/Game/Area/Action/actionAreaRecreateActorAction.h"

namespace ksys::game {

AreaRecreateActorAction::AreaRecreateActorAction(const InitArg& arg) : AreaActionBase(arg) {}

AreaRecreateActorAction::~AreaRecreateActorAction() = default;

bool AreaRecreateActorAction::init_(sead::Heap* heap) {
    return AreaActionBase::init_(heap);
}

}  // namespace ksys::game
