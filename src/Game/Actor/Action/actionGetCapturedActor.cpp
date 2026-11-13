#include "Game/Actor/Action/actionGetCapturedActor.h"

namespace uking::action {

GetCapturedActor::GetCapturedActor(const InitArg& arg) : GetItemBase(arg) {}

GetCapturedActor::~GetCapturedActor() = default;

bool GetCapturedActor::init_(sead::Heap* heap) {
    return GetItemBase::init_(heap);
}

void GetCapturedActor::enter_(ksys::act::ai::InlineParamPack* params) {
    GetItemBase::enter_(params);
}

void GetCapturedActor::leave_() {
    GetItemBase::leave_();
}

void GetCapturedActor::loadParams_() {
    GetItemBase::loadParams_();
}

void GetCapturedActor::calc_() {
    GetItemBase::calc_();
}

}  // namespace uking::action
