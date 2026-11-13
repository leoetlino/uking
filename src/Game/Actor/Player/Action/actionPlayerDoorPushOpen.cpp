#include "Game/Actor/Player/Action/actionPlayerDoorPushOpen.h"

namespace uking::action {

PlayerDoorPushOpen::PlayerDoorPushOpen(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDoorPushOpen::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDoorPushOpen::leave_() {
    PlayerBase::leave_();
}

void PlayerDoorPushOpen::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
