#include "Game/Actor/Player/Action/actionPlayerHorseGetOffInDemo.h"

namespace uking::action {

PlayerHorseGetOffInDemo::PlayerHorseGetOffInDemo(const InitArg& arg) : PlayerBase(arg) {}

void PlayerHorseGetOffInDemo::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerHorseGetOffInDemo::leave_() {
    PlayerBase::leave_();
}

void PlayerHorseGetOffInDemo::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
