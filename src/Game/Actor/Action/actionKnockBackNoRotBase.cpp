#include "Game/Actor/Action/actionKnockBackNoRotBase.h"

namespace uking::action {

KnockBackNoRotBase::KnockBackNoRotBase(const InitArg& arg) : KnockBackHitImpactForce(arg) {}

void KnockBackNoRotBase::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackHitImpactForce::enter_(params);
}

void KnockBackNoRotBase::calc_() {
    KnockBackHitImpactForce::calc_();
}

}  // namespace uking::action
