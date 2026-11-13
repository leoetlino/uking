#include "Game/Actor/Action/actionShutterOpenWait.h"

namespace uking::action {

ShutterOpenWait::ShutterOpenWait(const InitArg& arg) : act::ActionEx(arg) {}

ShutterOpenWait::~ShutterOpenWait() = default;

bool ShutterOpenWait::init_(sead::Heap* heap) {
    return act::ActionEx::init_(heap);
}

void ShutterOpenWait::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void ShutterOpenWait::leave_() {
    act::ActionEx::leave_();
}

void ShutterOpenWait::loadParams_() {
    getStaticParam(&mASName_s, "ASName");
    getMapUnitParam(&mMoveAxis_m, "MoveAxis");
    getMapUnitParam(&mMoveDis_m, "MoveDis");
}

void ShutterOpenWait::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
