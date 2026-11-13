#include "Game/Actor/Player/Action/actionPlayerSkin.h"

namespace uking::action {

PlayerSkin::PlayerSkin(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSkin::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSkin::leave_() {
    PlayerBase::leave_();
}

void PlayerSkin::loadParams_() {
    getStaticParam(&mWaitTime_s, "WaitTime");
}

void PlayerSkin::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
