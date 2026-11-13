#include "Game/Actor/Action/actionStopBase.h"

namespace uking::action {

StopBase::StopBase(const InitArg& arg) : act::ActionEx(arg) {}

void StopBase::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void StopBase::leave_() {
    act::ActionEx::leave_();
}

void StopBase::loadParams_() {
    getStaticParam(&mPosReduceRatio_s, "PosReduceRatio");
    getStaticParam(&mAngReduceRatio_s, "AngReduceRatio");
}

void StopBase::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
