#include "Game/Actor/Action/actionHorseSwimToTargetActor.h"

namespace uking::action {

HorseSwimToTargetActor::HorseSwimToTargetActor(const InitArg& arg) : HorseSwimBase(arg) {}

HorseSwimToTargetActor::~HorseSwimToTargetActor() = default;

bool HorseSwimToTargetActor::init_(sead::Heap* heap) {
    return HorseSwimBase::init_(heap);
}

void HorseSwimToTargetActor::enter_(ksys::act::ai::InlineParamPack* params) {
    HorseSwimBase::enter_(params);
}

void HorseSwimToTargetActor::leave_() {
    HorseSwimBase::leave_();
}

void HorseSwimToTargetActor::loadParams_() {
    HorseSwimBase::loadParams_();
    getDynamicParam(&mTargetActor_d, "TargetActor");
}

void HorseSwimToTargetActor::calc_() {
    HorseSwimBase::calc_();
}

}  // namespace uking::action
