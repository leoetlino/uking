#include "Game/Actor/Player/Action/actionPlayerUnequip.h"

namespace uking::action {

PlayerUnequip::PlayerUnequip(const InitArg& arg) : PlayerBase(arg) {}

PlayerUnequip::~PlayerUnequip() = default;

bool PlayerUnequip::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerUnequip::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerUnequip::leave_() {
    PlayerBase::leave_();
}

void PlayerUnequip::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
