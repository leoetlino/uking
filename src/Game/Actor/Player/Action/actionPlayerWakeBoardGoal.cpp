#include "Game/Actor/Player/Action/actionPlayerWakeBoardGoal.h"

namespace uking::action {

PlayerWakeBoardGoal::PlayerWakeBoardGoal(const InitArg& arg) : PlayerBase(arg) {}

PlayerWakeBoardGoal::~PlayerWakeBoardGoal() = default;

void PlayerWakeBoardGoal::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWakeBoardGoal::leave_() {
    PlayerBase::leave_();
}

void PlayerWakeBoardGoal::loadParams_() {
    getDynamicParam(&mASName_d, "ASName");
}

void PlayerWakeBoardGoal::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
