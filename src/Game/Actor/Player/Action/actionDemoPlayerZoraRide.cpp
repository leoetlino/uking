#include "Game/Actor/Player/Action/actionDemoPlayerZoraRide.h"

namespace uking::action {

DemoPlayerZoraRide::DemoPlayerZoraRide(const InitArg& arg) : PlayerBase(arg) {}

DemoPlayerZoraRide::~DemoPlayerZoraRide() = default;

bool DemoPlayerZoraRide::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void DemoPlayerZoraRide::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void DemoPlayerZoraRide::leave_() {
    PlayerBase::leave_();
}

void DemoPlayerZoraRide::loadParams_() {}

void DemoPlayerZoraRide::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
