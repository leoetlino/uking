#include "Game/Actor/Action/actionAreaActorObserveByActorTag.h"

namespace uking::action {

AreaActorObserveByActorTag::AreaActorObserveByActorTag(const InitArg& arg)
    : AreaObserveActorBase(arg) {}

AreaActorObserveByActorTag::~AreaActorObserveByActorTag() = default;

bool AreaActorObserveByActorTag::init_(sead::Heap* heap) {
    return AreaObserveActorBase::init_(heap);
}

}  // namespace uking::action
