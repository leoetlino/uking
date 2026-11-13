#include "Game/Actor/Action/actionKnockBackBackwardBase.h"

namespace uking::action {

KnockBackBackwardBase::KnockBackBackwardBase(const InitArg& arg) : KnockBackHitImpactForce(arg) {}

KnockBackBackwardBase::~KnockBackBackwardBase() = default;

bool KnockBackBackwardBase::init_(sead::Heap* heap) {
    return KnockBackHitImpactForce::init_(heap);
}

void KnockBackBackwardBase::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackHitImpactForce::enter_(params);
}

void KnockBackBackwardBase::leave_() {
    KnockBackHitImpactForce::leave_();
}

void KnockBackBackwardBase::loadParams_() {
    KnockBackHitImpactForce::loadParams_();
}

void KnockBackBackwardBase::calc_() {
    KnockBackHitImpactForce::calc_();
}

}  // namespace uking::action
