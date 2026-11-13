#include "Game/Actor/Action/actionGetSmallKeyItemGet.h"

namespace uking::action {

GetSmallKeyItemGet::GetSmallKeyItemGet(const InitArg& arg) : GetItemBase(arg) {}

void GetSmallKeyItemGet::enter_(ksys::act::ai::InlineParamPack* params) {
    GetItemBase::enter_(params);
}

void GetSmallKeyItemGet::leave_() {
    GetItemBase::leave_();
}

void GetSmallKeyItemGet::loadParams_() {
    GetItemBase::loadParams_();
}

void GetSmallKeyItemGet::calc_() {
    GetItemBase::calc_();
}

}  // namespace uking::action
