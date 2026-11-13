#include "Game/Actor/Action/actionGetRupee.h"

namespace uking::action {

GetRupee::GetRupee(const InitArg& arg) : GetItemBase(arg) {}

bool GetRupee::init_(sead::Heap* heap) {
    return GetItemBase::init_(heap);
}

void GetRupee::enter_(ksys::act::ai::InlineParamPack* params) {
    GetItemBase::enter_(params);
}

void GetRupee::leave_() {
    GetItemBase::leave_();
}

void GetRupee::loadParams_() {
    GetItemBase::loadParams_();
}

void GetRupee::calc_() {
    GetItemBase::calc_();
}

}  // namespace uking::action
