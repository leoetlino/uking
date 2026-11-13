#include "Game/Actor/Action/actionUnarmedAttack.h"

namespace uking::action {

UnarmedAttack::UnarmedAttack(const InitArg& arg) : act::ActionEx(arg) {}

UnarmedAttack::~UnarmedAttack() = default;

void UnarmedAttack::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void UnarmedAttack::leave_() {
    act::ActionEx::leave_();
}

void UnarmedAttack::loadParams_() {}

void UnarmedAttack::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
