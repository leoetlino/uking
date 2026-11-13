#include "Game/Actor/Player/Action/actionPlayerSuperBlow.h"

namespace uking::action {

PlayerSuperBlow::PlayerSuperBlow(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSuperBlow::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSuperBlow::leave_() {
    PlayerBase::leave_();
}

void PlayerSuperBlow::loadParams_() {
    getStaticParam(&mInitSpeed_s, "InitSpeed");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mDecSpeed_s, "DecSpeed");
    getStaticParam(&mNoRagdollTime_s, "NoRagdollTime");
}

void PlayerSuperBlow::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
