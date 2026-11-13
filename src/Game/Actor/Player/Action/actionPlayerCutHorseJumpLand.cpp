#include "Game/Actor/Player/Action/actionPlayerCutHorseJumpLand.h"

namespace uking::action {

PlayerCutHorseJumpLand::PlayerCutHorseJumpLand(const InitArg& arg) : PlayerBase(arg) {}

void PlayerCutHorseJumpLand::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCutHorseJumpLand::leave_() {
    PlayerBase::leave_();
}

void PlayerCutHorseJumpLand::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
