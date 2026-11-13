#include "Game/Actor/Player/Action/actionPlayerStainWait.h"

namespace uking::action {

PlayerStainWait::PlayerStainWait(const InitArg& arg) : PlayerBase(arg) {}

PlayerStainWait::~PlayerStainWait() = default;

bool PlayerStainWait::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerStainWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerStainWait::leave_() {
    PlayerBase::leave_();
}

void PlayerStainWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
