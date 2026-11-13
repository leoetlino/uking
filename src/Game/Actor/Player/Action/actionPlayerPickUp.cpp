#include "Game/Actor/Player/Action/actionPlayerPickUp.h"

namespace uking::action {

PlayerPickUp::PlayerPickUp(const InitArg& arg) : PlayerBase(arg) {}

PlayerPickUp::~PlayerPickUp() = default;

bool PlayerPickUp::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerPickUp::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerPickUp::leave_() {
    PlayerBase::leave_();
}

void PlayerPickUp::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
