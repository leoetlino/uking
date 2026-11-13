#include "Game/Actor/Action/actionLargeDamage.h"

namespace uking::action {

LargeDamage::LargeDamage(const InitArg& arg) : act::ActionEx(arg) {}

LargeDamage::~LargeDamage() = default;

void LargeDamage::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void LargeDamage::leave_() {
    act::ActionEx::leave_();
}

void LargeDamage::loadParams_() {
    getStaticParam(&mActionTime_s, "ActionTime");
}

void LargeDamage::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
