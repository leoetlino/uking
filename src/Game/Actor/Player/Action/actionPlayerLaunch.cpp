#include "Game/Actor/Player/Action/actionPlayerLaunch.h"

namespace uking::action {

PlayerLaunch::PlayerLaunch(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLaunch::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLaunch::leave_() {
    PlayerBase::leave_();
}

void PlayerLaunch::loadParams_() {
    getStaticParam(&mInitSpeed_s, "InitSpeed");
    getStaticParam(&mJumpHeight_s, "JumpHeight");
    getStaticParam(&mAddLinearImpulse_s, "AddLinearImpulse");
    getStaticParam(&mAddRollImpulse_s, "AddRollImpulse");
    getStaticParam(&mNoRagdollTime_s, "NoRagdollTime");
    getStaticParam(&mDamage_s, "Damage");
    getDynamicParam(&mBasePos_d, "BasePos");
}

void PlayerLaunch::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
