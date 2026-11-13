#include "Game/Actor/Action/actionAnmDamage.h"

namespace uking::action {

AnmDamage::AnmDamage(const InitArg& arg) : KnockBackNoRotBase(arg) {}

AnmDamage::~AnmDamage() = default;

bool AnmDamage::init_(sead::Heap* heap) {
    return KnockBackNoRotBase::init_(heap);
}

void AnmDamage::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackNoRotBase::enter_(params);
}

void AnmDamage::leave_() {
    KnockBackNoRotBase::leave_();
}

void AnmDamage::loadParams_() {
    KnockBackHitImpactForce::loadParams_();
    getStaticParam(&mAS_s, "AS");
}

void AnmDamage::calc_() {
    KnockBackNoRotBase::calc_();
}

}  // namespace uking::action
