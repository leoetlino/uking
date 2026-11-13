#include "Game/Actor/Player/Action/actionPlayerFall.h"

namespace uking::action {

PlayerFall::PlayerFall(const InitArg& arg) : PlayerBase(arg) {}

void PlayerFall::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerFall::leave_() {
    PlayerBase::leave_();
}

void PlayerFall::loadParams_() {
    getStaticParam(&mNoClimbTime_s, "NoClimbTime");
    getStaticParam(&mNoClimbTimeTired_s, "NoClimbTimeTired");
    getStaticParam(&mNoDispDisableAppTime_s, "NoDispDisableAppTime");
}

void PlayerFall::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
