#include "Game/Actor/Player/Action/actionPlayerSpAttack.h"

namespace uking::action {

PlayerSpAttack::PlayerSpAttack(const InitArg& arg) : PlayerBase(arg) {}

void PlayerSpAttack::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerSpAttack::leave_() {
    PlayerBase::leave_();
}

void PlayerSpAttack::loadParams_() {
    getStaticParam(&mSwordSearchFrame_s, "SwordSearchFrame");
    getStaticParam(&mSwordSearchAngle_s, "SwordSearchAngle");
}

void PlayerSpAttack::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
