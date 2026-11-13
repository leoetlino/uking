#include "Game/Actor/Action/actionGetItemBase.h"

namespace uking::action {

GetItemBase::GetItemBase(const InitArg& arg) : ksys::act::ai::Action(arg) {}

bool GetItemBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void GetItemBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void GetItemBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void GetItemBase::loadParams_() {}

void GetItemBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
