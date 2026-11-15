#include "Game/Actor/Action/actionTargetCircleMove.h"

namespace uking::action {

TargetCircleMove::TargetCircleMove(const InitArg& arg) : ksys::act::ai::Action(arg) {}

TargetCircleMove::~TargetCircleMove() = default;

bool TargetCircleMove::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void TargetCircleMove::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void TargetCircleMove::leave_() {
    ksys::act::ai::Action::leave_();
}

void TargetCircleMove::loadParams_() {
    getStaticParam(&mSpeed_s, "Speed");
    getStaticParam(&mRotSpd_s, "RotSpd");
    getStaticParam(&mRotDist_s, "RotDist");
    getDynamicParam(&mRotDir_d, "RotDir");
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

void TargetCircleMove::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
