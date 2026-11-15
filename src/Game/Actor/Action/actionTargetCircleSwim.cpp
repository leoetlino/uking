#include "Game/Actor/Action/actionTargetCircleSwim.h"

namespace uking::action {

TargetCircleSwim::TargetCircleSwim(const InitArg& arg) : TargetCircleMove(arg) {}

TargetCircleSwim::~TargetCircleSwim() = default;

void TargetCircleSwim::enter_(ksys::act::ai::InlineParamPack* params) {
    TargetCircleMove::enter_(params);
}

void TargetCircleSwim::leave_() {
    TargetCircleMove::leave_();
}

void TargetCircleSwim::loadParams_() {
    TargetCircleMove::loadParams_();
    getStaticParam(&mFloatDepth_s, "FloatDepth");
    getStaticParam(&mFloatRadius_s, "FloatRadius");
    getStaticParam(&mFloatCycleTime_s, "FloatCycleTime");
    getStaticParam(&mInWaterDepth_s, "InWaterDepth");
    getStaticParam(&mChangeDepthSpeed_s, "ChangeDepthSpeed");
}

}  // namespace uking::action
