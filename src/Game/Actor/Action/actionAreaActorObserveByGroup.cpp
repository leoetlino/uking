#include "Game/Actor/Action/actionAreaActorObserveByGroup.h"

namespace uking::action {

AreaActorObserveByGroup::AreaActorObserveByGroup(const InitArg& arg) : AreaObserveActorBase(arg) {}

AreaActorObserveByGroup::~AreaActorObserveByGroup() = default;

bool AreaActorObserveByGroup::init_(sead::Heap* heap) {
    return AreaObserveActorBase::init_(heap);
}

}  // namespace uking::action
