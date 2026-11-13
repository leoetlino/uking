#include "Game/Actor/Player/Action/actionPlayerBow.h"

namespace uking::action {

PlayerBow::PlayerBow(const InitArg& arg) : PlayerBase(arg) {}

void PlayerBow::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerBow::leave_() {
    PlayerBase::leave_();
}

void PlayerBow::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
