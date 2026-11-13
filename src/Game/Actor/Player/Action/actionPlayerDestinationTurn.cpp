#include "Game/Actor/Player/Action/actionPlayerDestinationTurn.h"

namespace uking::action {

PlayerDestinationTurn::PlayerDestinationTurn(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDestinationTurn::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDestinationTurn::leave_() {
    PlayerBase::leave_();
}

void PlayerDestinationTurn::loadParams_() {
    getDynamicParam(&mDestPosX_d, "DestPosX");
    getDynamicParam(&mDestPosY_d, "DestPosY");
    getDynamicParam(&mDestPosZ_d, "DestPosZ");
}

void PlayerDestinationTurn::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
