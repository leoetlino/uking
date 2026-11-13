#include "Game/Actor/Action/actionReloadArrow.h"

namespace uking::action {

ReloadArrow::ReloadArrow(const InitArg& arg) : act::ActionEx(arg) {}

ReloadArrow::~ReloadArrow() = default;

void ReloadArrow::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void ReloadArrow::leave_() {
    act::ActionEx::leave_();
}

void ReloadArrow::loadParams_() {}

void ReloadArrow::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
