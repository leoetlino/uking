#include "Game/Actor/Action/actionCapturedActKnockBack.h"

namespace uking::action {

CapturedActKnockBack::CapturedActKnockBack(const InitArg& arg) : KnockBackNoRotBase(arg) {}

CapturedActKnockBack::~CapturedActKnockBack() = default;

bool CapturedActKnockBack::init_(sead::Heap* heap) {
    return KnockBackNoRotBase::init_(heap);
}

void CapturedActKnockBack::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackNoRotBase::enter_(params);
}

void CapturedActKnockBack::leave_() {
    KnockBackNoRotBase::leave_();
}

void CapturedActKnockBack::loadParams_() {
    KnockBackHitImpactForce::loadParams_();
}

void CapturedActKnockBack::calc_() {
    KnockBackNoRotBase::calc_();
}

}  // namespace uking::action
