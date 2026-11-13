#include "Game/Actor/Action/actionGetItemGet.h"

namespace uking::action {

GetItemGet::GetItemGet(const InitArg& arg) : GetItemBase(arg) {}

void GetItemGet::enter_(ksys::act::ai::InlineParamPack* params) {
    GetItemBase::enter_(params);
}

void GetItemGet::leave_() {
    GetItemBase::leave_();
}

void GetItemGet::loadParams_() {
    GetItemBase::loadParams_();
}

void GetItemGet::calc_() {
    GetItemBase::calc_();
}

}  // namespace uking::action
