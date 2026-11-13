#include "Game/Actor/Player/Action/actionPlayerWaterFall.h"

namespace uking::action {

PlayerWaterFall::PlayerWaterFall(const InitArg& arg) : PlayerBase(arg) {}

PlayerWaterFall::~PlayerWaterFall() = default;

void PlayerWaterFall::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWaterFall::leave_() {
    PlayerBase::leave_();
}

void PlayerWaterFall::loadParams_() {
    getStaticParam(&mSpeedClimb_s, "SpeedClimb");
    getDynamicParam(&mRailPtr_d, "RailPtr");
    getDynamicParam(&mFrontDir_d, "FrontDir");
}

void PlayerWaterFall::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
