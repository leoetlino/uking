#include "Game/Actor/Player/Action/actionPlayerLadderJump.h"

namespace uking::action {

PlayerLadderJump::PlayerLadderJump(const InitArg& arg) : PlayerBase(arg) {}

void PlayerLadderJump::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerLadderJump::leave_() {
    PlayerBase::leave_();
}

void PlayerLadderJump::loadParams_() {
    getStaticParam(&mEnergyJump_s, "EnergyJump");
}

void PlayerLadderJump::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
