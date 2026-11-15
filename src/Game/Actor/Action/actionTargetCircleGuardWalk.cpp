#include "Game/Actor/Action/actionTargetCircleGuardWalk.h"

namespace uking::action {

TargetCircleGuardWalk::TargetCircleGuardWalk(const InitArg& arg) : TargetCircleMove(arg) {}

bool TargetCircleGuardWalk::init_(sead::Heap* heap) {
    return TargetCircleMove::init_(heap);
}

void TargetCircleGuardWalk::enter_(ksys::act::ai::InlineParamPack* params) {
    TargetCircleMove::enter_(params);
}

void TargetCircleGuardWalk::leave_() {
    TargetCircleMove::leave_();
}

void TargetCircleGuardWalk::loadParams_() {
    TargetCircleMove::loadParams_();
}

void TargetCircleGuardWalk::calc_() {
    TargetCircleMove::calc_();
}

}  // namespace uking::action
