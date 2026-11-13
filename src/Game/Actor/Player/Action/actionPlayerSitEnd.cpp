#include "Game/Actor/Player/Action/actionPlayerSitEnd.h"

namespace uking::action {

PlayerSitEnd::PlayerSitEnd(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSitEnd::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSitEnd::leave_() {
    PlayerBase::leave_();
}

void PlayerSitEnd::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
