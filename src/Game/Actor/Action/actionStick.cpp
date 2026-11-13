#include "Game/Actor/Action/actionStick.h"

namespace uking::action {

Stick::Stick(const InitArg& arg) : act::ActionEx(arg) {}

Stick::~Stick() = default;

void Stick::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void Stick::leave_() {
    act::ActionEx::leave_();
}

void Stick::loadParams_() {}

void Stick::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
