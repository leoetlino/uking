#include "KingSystem/Game/Area/Action/actionAreaOutRecreateActorAction.h"

namespace ksys::game {

AreaOutRecreateActorAction::AreaOutRecreateActorAction(const InitArg& arg) : AreaActionBase(arg) {}

AreaOutRecreateActorAction::~AreaOutRecreateActorAction() = default;

bool AreaOutRecreateActorAction::init_(sead::Heap* heap) {
    return AreaActionBase::init_(heap);
}

}  // namespace ksys::game
