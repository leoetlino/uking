#include "Game/Actor/Action/actionGanonSmallDamage.h"

namespace uking::action {

GanonSmallDamage::GanonSmallDamage(const InitArg& arg) : KnockBackNoRotBase(arg) {}

GanonSmallDamage::~GanonSmallDamage() = default;

bool GanonSmallDamage::init_(sead::Heap* heap) {
    return KnockBackNoRotBase::init_(heap);
}

void GanonSmallDamage::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackNoRotBase::enter_(params);
}

void GanonSmallDamage::leave_() {
    KnockBackNoRotBase::leave_();
}

void GanonSmallDamage::loadParams_() {
    KnockBackHitImpactForce::loadParams_();
    getStaticParam(&mUpAS_s, "UpAS");
    getStaticParam(&mAS_s, "AS");
}

void GanonSmallDamage::calc_() {
    KnockBackNoRotBase::calc_();
}

}  // namespace uking::action
