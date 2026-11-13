#include "Game/Actor/Action/actionLandRagdoll.h"

namespace uking::action {

LandRagdoll::LandRagdoll(const InitArg& arg) : RagdollGetUpBase(arg) {}

LandRagdoll::~LandRagdoll() = default;

bool LandRagdoll::init_(sead::Heap* heap) {
    return RagdollGetUpBase::init_(heap);
}

void LandRagdoll::enter_(ksys::act::ai::InlineParamPack* params) {
    RagdollGetUpBase::enter_(params);
}

void LandRagdoll::leave_() {
    RagdollGetUpBase::leave_();
}

void LandRagdoll::loadParams_() {
    RagdollGetUpBase::loadParams_();
}

void LandRagdoll::calc_() {
    RagdollGetUpBase::calc_();
}

}  // namespace uking::action
