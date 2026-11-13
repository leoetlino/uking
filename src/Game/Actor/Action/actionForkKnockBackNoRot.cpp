#include "Game/Actor/Action/actionForkKnockBackNoRot.h"

namespace uking::action {

ForkKnockBackNoRot::ForkKnockBackNoRot(const InitArg& arg) : KnockBackNoRotBase(arg) {}

ForkKnockBackNoRot::~ForkKnockBackNoRot() = default;

bool ForkKnockBackNoRot::init_(sead::Heap* heap) {
    return KnockBackNoRotBase::init_(heap);
}

void ForkKnockBackNoRot::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackNoRotBase::enter_(params);
}

void ForkKnockBackNoRot::leave_() {
    KnockBackNoRotBase::leave_();
}

void ForkKnockBackNoRot::loadParams_() {
    KnockBackHitImpactForce::loadParams_();
}

void ForkKnockBackNoRot::calc_() {
    KnockBackNoRotBase::calc_();
}

}  // namespace uking::action
