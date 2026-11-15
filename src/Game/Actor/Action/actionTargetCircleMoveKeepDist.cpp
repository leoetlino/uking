#include "Game/Actor/Action/actionTargetCircleMoveKeepDist.h"

namespace uking::action {

TargetCircleMoveKeepDist::TargetCircleMoveKeepDist(const InitArg& arg) : TargetCircleMove(arg) {}

TargetCircleMoveKeepDist::~TargetCircleMoveKeepDist() = default;

bool TargetCircleMoveKeepDist::init_(sead::Heap* heap) {
    return TargetCircleMove::init_(heap);
}

void TargetCircleMoveKeepDist::enter_(ksys::act::ai::InlineParamPack* params) {
    TargetCircleMove::enter_(params);
}

void TargetCircleMoveKeepDist::leave_() {
    TargetCircleMove::leave_();
}

void TargetCircleMoveKeepDist::loadParams_() {
    TargetCircleMove::loadParams_();
    getStaticParam(&mASName_s, "ASName");
}

void TargetCircleMoveKeepDist::calc_() {
    TargetCircleMove::calc_();
}

}  // namespace uking::action
