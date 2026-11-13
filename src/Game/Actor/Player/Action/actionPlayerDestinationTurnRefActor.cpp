#include "Game/Actor/Player/Action/actionPlayerDestinationTurnRefActor.h"

namespace uking::action {

PlayerDestinationTurnRefActor::PlayerDestinationTurnRefActor(const InitArg& arg)
    : PlayerBase(arg) {}

PlayerDestinationTurnRefActor::~PlayerDestinationTurnRefActor() = default;

void PlayerDestinationTurnRefActor::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDestinationTurnRefActor::leave_() {
    PlayerBase::leave_();
}

void PlayerDestinationTurnRefActor::loadParams_() {
    getDynamicParam(&mUniqName_d, "UniqName");
}

void PlayerDestinationTurnRefActor::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
