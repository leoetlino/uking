#include "Game/Actor/Player/Action/actionPlayerSideStepLand.h"

namespace uking::action {

PlayerSideStepLand::PlayerSideStepLand(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSideStepLand::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSideStepLand::leave_() {
    PlayerBase::leave_();
}

void PlayerSideStepLand::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
