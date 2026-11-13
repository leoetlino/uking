#include "Game/Actor/Player/Action/actionPlayerHide.h"

namespace uking::action {

PlayerHide::PlayerHide(const InitArg& arg) : PlayerBase(arg) {}

PlayerHide::~PlayerHide() = default;

bool PlayerHide::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerHide::loadParams_() {
    getStaticParam(&mHidden_s, "Hidden");
}

}  // namespace uking::action
