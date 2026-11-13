#include "Game/Actor/Player/Action/actionPlayerSitWait.h"

namespace uking::action {

PlayerSitWait::PlayerSitWait(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSitWait::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSitWait::leave_() {
    PlayerBase::leave_();
}

void PlayerSitWait::loadParams_() {
    getStaticParam(&mAutoRecoverRate_s, "AutoRecoverRate");
    getStaticParam(&mEnergyAutoRecover_s, "EnergyAutoRecover");
}

void PlayerSitWait::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
