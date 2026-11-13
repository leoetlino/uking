#include "Game/Actor/Player/Action/actionPlayerTurnInner.h"

namespace uking::action {

PlayerTurnInner::PlayerTurnInner(const InitArg& arg) : PlayerBase(arg) {}

PlayerTurnInner::~PlayerTurnInner() = default;

bool PlayerTurnInner::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerTurnInner::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerTurnInner::leave_() {
    PlayerBase::leave_();
}

void PlayerTurnInner::loadParams_() {}

void PlayerTurnInner::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
