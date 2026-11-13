#include "Game/Actor/Player/Action/actionPlayerWarp.h"

namespace uking::action {

PlayerWarp::PlayerWarp(const InitArg& arg) : PlayerBase(arg) {}

void PlayerWarp::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWarp::leave_() {
    PlayerBase::leave_();
}

void PlayerWarp::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
