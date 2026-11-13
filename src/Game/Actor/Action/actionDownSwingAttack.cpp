#include "Game/Actor/Action/actionDownSwingAttack.h"

namespace uking::action {

DownSwingAttack::DownSwingAttack(const InitArg& arg) : act::ActionEx(arg) {}

DownSwingAttack::~DownSwingAttack() = default;

void DownSwingAttack::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void DownSwingAttack::leave_() {
    act::ActionEx::leave_();
}

void DownSwingAttack::loadParams_() {}

void DownSwingAttack::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
