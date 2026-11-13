#include "Game/Actor/Action/actionShutterOpen.h"

namespace uking::action {

ShutterOpen::ShutterOpen(const InitArg& arg) : act::ActionEx(arg) {}

ShutterOpen::~ShutterOpen() = default;

bool ShutterOpen::init_(sead::Heap* heap) {
    return act::ActionEx::init_(heap);
}

void ShutterOpen::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void ShutterOpen::leave_() {
    act::ActionEx::leave_();
}

void ShutterOpen::loadParams_() {
    getStaticParam(&mOnLink_s, "OnLink");
    getStaticParam(&mIsPreOpen_s, "IsPreOpen");
    getStaticParam(&mASName_s, "ASName");
    getMapUnitParam(&mMoveAxis_m, "MoveAxis");
    getMapUnitParam(&mMoveDis_m, "MoveDis");
    getMapUnitParam(&mMoveSpeed_m, "MoveSpeed");
}

void ShutterOpen::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
