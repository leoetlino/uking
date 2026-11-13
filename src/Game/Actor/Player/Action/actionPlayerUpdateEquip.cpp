#include "Game/Actor/Player/Action/actionPlayerUpdateEquip.h"

namespace uking::action {

PlayerUpdateEquip::PlayerUpdateEquip(const InitArg& arg) : PlayerBase(arg) {}

PlayerUpdateEquip::~PlayerUpdateEquip() = default;

bool PlayerUpdateEquip::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerUpdateEquip::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerUpdateEquip::leave_() {
    PlayerBase::leave_();
}

void PlayerUpdateEquip::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
