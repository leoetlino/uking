#include "Game/Actor/Player/Action/actionPlayerSuperJump.h"

namespace uking::action {

PlayerSuperJump::PlayerSuperJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSuperJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSuperJump::leave_() {
    PlayerBase::leave_();
}

void PlayerSuperJump::loadParams_() {
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mWindScale_s, "WindScale");
}

void PlayerSuperJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
