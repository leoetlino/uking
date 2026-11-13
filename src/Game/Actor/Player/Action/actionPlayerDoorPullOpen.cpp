#include "Game/Actor/Player/Action/actionPlayerDoorPullOpen.h"

namespace uking::action {

PlayerDoorPullOpen::PlayerDoorPullOpen(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDoorPullOpen::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDoorPullOpen::leave_() {
    PlayerBase::leave_();
}

void PlayerDoorPullOpen::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
