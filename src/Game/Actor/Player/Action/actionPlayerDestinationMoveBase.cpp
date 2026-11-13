#include "Game/Actor/Player/Action/actionPlayerDestinationMoveBase.h"

namespace uking::action {

PlayerDestinationMoveBase::PlayerDestinationMoveBase(const InitArg& arg) : PlayerBase(arg) {}

void PlayerDestinationMoveBase::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDestinationMoveBase::leave_() {
    PlayerBase::leave_();
}

void PlayerDestinationMoveBase::loadParams_() {
    getStaticParam(&mDecSpdDist_s, "DecSpdDist");
    getDynamicParam(&mStickValue_d, "StickValue");
    getStaticParam(&mForceTurnDist_s, "ForceTurnDist");
}

void PlayerDestinationMoveBase::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
