#include "Game/Actor/Player/Action/actionPlayerDead.h"

namespace uking::action {

PlayerDead::PlayerDead(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDead::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDead::leave_() {
    PlayerBase::leave_();
}

void PlayerDead::loadParams_() {
    getStaticParam(&mRagdollChangeTime_s, "RagdollChangeTime");
}

void PlayerDead::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
