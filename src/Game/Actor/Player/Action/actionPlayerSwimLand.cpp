#include "Game/Actor/Player/Action/actionPlayerSwimLand.h"

namespace uking::action {

PlayerSwimLand::PlayerSwimLand(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSwimLand::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSwimLand::leave_() {
    PlayerBase::leave_();
}

void PlayerSwimLand::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
