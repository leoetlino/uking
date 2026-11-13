#include "Game/Actor/Player/Action/actionPlayerCleaningAround.h"

namespace uking::action {

PlayerCleaningAround::PlayerCleaningAround(const InitArg& arg) : PlayerBase(arg) {}

PlayerCleaningAround::~PlayerCleaningAround() = default;

bool PlayerCleaningAround::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerCleaningAround::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerCleaningAround::leave_() {
    PlayerBase::leave_();
}

void PlayerCleaningAround::loadParams_() {
    getStaticParam(&mCleaningTime_s, "CleaningTime");
}

void PlayerCleaningAround::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
