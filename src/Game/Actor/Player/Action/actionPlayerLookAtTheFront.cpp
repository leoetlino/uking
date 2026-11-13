#include "Game/Actor/Player/Action/actionPlayerLookAtTheFront.h"

namespace uking::action {

PlayerLookAtTheFront::PlayerLookAtTheFront(const InitArg& arg) : PlayerBase(arg) {}

PlayerLookAtTheFront::~PlayerLookAtTheFront() = default;

bool PlayerLookAtTheFront::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerLookAtTheFront::loadParams_() {
    getDynamicParam(&mIsValid_d, "IsValid");
}

}  // namespace uking::action
