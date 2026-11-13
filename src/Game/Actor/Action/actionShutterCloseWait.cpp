#include "Game/Actor/Action/actionShutterCloseWait.h"

namespace uking::action {

ShutterCloseWait::ShutterCloseWait(const InitArg& arg) : act::ActionEx(arg) {}

ShutterCloseWait::~ShutterCloseWait() = default;

bool ShutterCloseWait::init_(sead::Heap* heap) {
    return act::ActionEx::init_(heap);
}

void ShutterCloseWait::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void ShutterCloseWait::leave_() {
    act::ActionEx::leave_();
}

void ShutterCloseWait::loadParams_() {
    getStaticParam(&mASName_s, "ASName");
}

void ShutterCloseWait::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
