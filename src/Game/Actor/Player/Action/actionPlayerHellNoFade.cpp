#include "Game/Actor/Player/Action/actionPlayerHellNoFade.h"

namespace uking::action {

PlayerHellNoFade::PlayerHellNoFade(const InitArg& arg) : PlayerBase(arg) {}

void PlayerHellNoFade::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerHellNoFade::leave_() {
    PlayerBase::leave_();
}

void PlayerHellNoFade::loadParams_() {
    getStaticParam(&mCleaningTime_s, "CleaningTime");
}

void PlayerHellNoFade::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
