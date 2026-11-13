#include "Game/Actor/Player/Action/actionPlayerGrabThrow.h"

namespace uking::action {

PlayerGrabThrow::PlayerGrabThrow(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGrabThrow::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGrabThrow::leave_() {
    PlayerBase::leave_();
}

void PlayerGrabThrow::loadParams_() {
    getStaticParam(&mOverThrowSpeedYB_s, "OverThrowSpeedYB");
    getStaticParam(&mOverThrowSpeedFB_s, "OverThrowSpeedFB");
    getStaticParam(&mOverThrowSpeedYL_s, "OverThrowSpeedYL");
    getStaticParam(&mOverThrowSpeedFL_s, "OverThrowSpeedFL");
    getStaticParam(&mOverThrowInertiaRate_s, "OverThrowInertiaRate");
}

void PlayerGrabThrow::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
