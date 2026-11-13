#include "Game/Actor/Action/actionThrownDown.h"

namespace uking::action {

ThrownDown::ThrownDown(const InitArg& arg) : RagdollGetUpBase(arg) {}

ThrownDown::~ThrownDown() = default;

bool ThrownDown::init_(sead::Heap* heap) {
    return RagdollGetUpBase::init_(heap);
}

void ThrownDown::enter_(ksys::act::ai::InlineParamPack* params) {
    RagdollGetUpBase::enter_(params);
}

void ThrownDown::leave_() {
    RagdollGetUpBase::leave_();
}

void ThrownDown::loadParams_() {
    RagdollGetUpBase::loadParams_();
    getDynamicParam(&mSetupSpeed_d, "SetupSpeed");
}

void ThrownDown::calc_() {
    RagdollGetUpBase::calc_();
}

}  // namespace uking::action
