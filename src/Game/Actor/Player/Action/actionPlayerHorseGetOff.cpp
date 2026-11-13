#include "Game/Actor/Player/Action/actionPlayerHorseGetOff.h"

namespace uking::action {

PlayerHorseGetOff::PlayerHorseGetOff(const InitArg& arg) : PlayerBase(arg) {}

void PlayerHorseGetOff::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerHorseGetOff::leave_() {
    PlayerBase::leave_();
}

void PlayerHorseGetOff::loadParams_() {
    getStaticParam(&mSideFallSpeed_s, "SideFallSpeed");
}

void PlayerHorseGetOff::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
