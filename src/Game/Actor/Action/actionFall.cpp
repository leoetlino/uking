#include "Game/Actor/Action/actionFall.h"

namespace uking::action {

Fall::Fall(const InitArg& arg) : act::ActionEx(arg) {}

Fall::~Fall() = default;

void Fall::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void Fall::leave_() {
    act::ActionEx::leave_();
}

void Fall::loadParams_() {
    getStaticParam(&mInWaterDepth_s, "InWaterDepth");
    getStaticParam(&mASName_s, "ASName");
}

void Fall::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
