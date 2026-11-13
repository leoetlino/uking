#include "Game/Actor/Player/Action/actionPlayerSetVisibleWeapon.h"

namespace uking::action {

PlayerSetVisibleWeapon::PlayerSetVisibleWeapon(const InitArg& arg) : PlayerBase(arg) {}

PlayerSetVisibleWeapon::~PlayerSetVisibleWeapon() = default;

bool PlayerSetVisibleWeapon::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerSetVisibleWeapon::loadParams_() {
    getDynamicParam(&mSetVisible_d, "SetVisible");
}

}  // namespace uking::action
