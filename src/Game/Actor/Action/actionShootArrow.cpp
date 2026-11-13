#include "Game/Actor/Action/actionShootArrow.h"

namespace uking::action {

ShootArrow::ShootArrow(const InitArg& arg) : act::ActionEx(arg) {}

ShootArrow::~ShootArrow() = default;

void ShootArrow::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void ShootArrow::loadParams_() {}

void ShootArrow::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
