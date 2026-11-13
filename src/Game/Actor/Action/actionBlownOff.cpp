#include "Game/Actor/Action/actionBlownOff.h"

namespace uking::action {

BlownOff::BlownOff(const InitArg& arg) : RagdollGetUpBase(arg) {}

BlownOff::~BlownOff() = default;

bool BlownOff::init_(sead::Heap* heap) {
    return RagdollGetUpBase::init_(heap);
}

void BlownOff::enter_(ksys::act::ai::InlineParamPack* params) {
    RagdollGetUpBase::enter_(params);
}

void BlownOff::leave_() {
    RagdollGetUpBase::leave_();
}

void BlownOff::loadParams_() {
    getStaticParam(&mAddTime_s, "AddTime");
    getStaticParam(&mLifeReflexRatio_s, "LifeReflexRatio");
    getStaticParam(&mImpulseRatio_s, "ImpulseRatio");
    RagdollGetUpBase::loadParams_();
}

void BlownOff::calc_() {
    RagdollGetUpBase::calc_();
}

}  // namespace uking::action
