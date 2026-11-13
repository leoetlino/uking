#include "Game/Actor/Player/Action/actionPlayerSitStart.h"

namespace uking::action {

PlayerSitStart::PlayerSitStart(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSitStart::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSitStart::leave_() {
    PlayerBase::leave_();
}

void PlayerSitStart::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
