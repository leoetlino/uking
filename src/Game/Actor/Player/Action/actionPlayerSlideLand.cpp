#include "Game/Actor/Player/Action/actionPlayerSlideLand.h"

namespace uking::action {

PlayerSlideLand::PlayerSlideLand(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSlideLand::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSlideLand::leave_() {
    PlayerBase::leave_();
}

void PlayerSlideLand::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
