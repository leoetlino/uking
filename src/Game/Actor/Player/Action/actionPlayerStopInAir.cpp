#include "Game/Actor/Player/Action/actionPlayerStopInAir.h"

namespace uking::action {

PlayerStopInAir::PlayerStopInAir(const InitArg& arg) : PlayerBase(arg) {}

void PlayerStopInAir::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerStopInAir::leave_() {
    PlayerBase::leave_();
}

void PlayerStopInAir::loadParams_() {
    getDynamicParam(&mNoFixed_d, "NoFixed");
}

void PlayerStopInAir::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
