#include "Game/Actor/Action/actionEscapeBackTurn.h"

namespace uking::action {

EscapeBackTurn::EscapeBackTurn(const InitArg& arg) : act::ActionEx(arg) {}

EscapeBackTurn::~EscapeBackTurn() = default;

void EscapeBackTurn::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void EscapeBackTurn::leave_() {
    act::ActionEx::leave_();
}

void EscapeBackTurn::loadParams_() {}

void EscapeBackTurn::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
