#include "Game/Actor/Player/Action/actionPlayerHellStartWait.h"

namespace uking::action {

PlayerHellStartWait::PlayerHellStartWait(const InitArg& arg) : PlayerBase(arg) {}

PlayerHellStartWait::~PlayerHellStartWait() = default;

void PlayerHellStartWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerHellStartWait::leave_() {
    PlayerBase::leave_();
}

void PlayerHellStartWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
