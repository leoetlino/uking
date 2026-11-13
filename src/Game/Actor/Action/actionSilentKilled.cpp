#include "Game/Actor/Action/actionSilentKilled.h"

namespace uking::action {

SilentKilled::SilentKilled(const InitArg& arg) : RagdollGetUpBase(arg) {}

SilentKilled::~SilentKilled() = default;

bool SilentKilled::init_(sead::Heap* heap) {
    return RagdollGetUpBase::init_(heap);
}

void SilentKilled::enter_(ksys::act::ai::InlineParamPack* params) {
    RagdollGetUpBase::enter_(params);
}

void SilentKilled::leave_() {
    RagdollGetUpBase::leave_();
}

void SilentKilled::loadParams_() {
    RagdollGetUpBase::loadParams_();
}

void SilentKilled::calc_() {
    RagdollGetUpBase::calc_();
}

}  // namespace uking::action
