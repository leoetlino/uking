#include "Game/Actor/Action/actionTargetCircleWalk.h"

namespace uking::action {

TargetCircleWalk::TargetCircleWalk(const InitArg& arg) : TargetCircleMove(arg) {}

bool TargetCircleWalk::init_(sead::Heap* heap) {
    return TargetCircleMove::init_(heap);
}

void TargetCircleWalk::enter_(ksys::act::ai::InlineParamPack* params) {
    TargetCircleMove::enter_(params);
}

void TargetCircleWalk::leave_() {
    TargetCircleMove::leave_();
}

void TargetCircleWalk::loadParams_() {
    TargetCircleMove::loadParams_();
}

void TargetCircleWalk::calc_() {
    TargetCircleMove::calc_();
}

}  // namespace uking::action
