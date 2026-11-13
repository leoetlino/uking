#include "Game/Actor/Action/actionGetItemIntoBag.h"

namespace uking::action {

GetItemIntoBag::GetItemIntoBag(const InitArg& arg) : GetItemBase(arg) {}

void GetItemIntoBag::enter_(ksys::act::ai::InlineParamPack* params) {
    GetItemBase::enter_(params);
}

void GetItemIntoBag::leave_() {
    GetItemBase::leave_();
}

void GetItemIntoBag::loadParams_() {
    GetItemBase::loadParams_();
}

void GetItemIntoBag::calc_() {
    GetItemBase::calc_();
}

}  // namespace uking::action
