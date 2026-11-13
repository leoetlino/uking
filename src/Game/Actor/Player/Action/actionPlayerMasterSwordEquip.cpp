#include "Game/Actor/Player/Action/actionPlayerMasterSwordEquip.h"

namespace uking::action {

PlayerMasterSwordEquip::PlayerMasterSwordEquip(const InitArg& arg) : PlayerBase(arg) {}

PlayerMasterSwordEquip::~PlayerMasterSwordEquip() = default;

bool PlayerMasterSwordEquip::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

}  // namespace uking::action
