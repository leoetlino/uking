#include "Game/Actor/AI/aiCircleMoveInWater.h"

namespace uking::ai {

CircleMoveInWater::CircleMoveInWater(const InitArg& arg) : CircleMoveFluid(arg) {}

CircleMoveInWater::~CircleMoveInWater() = default;

bool CircleMoveInWater::init_(sead::Heap* heap) {
    return CircleMoveFluid::init_(heap);
}

void CircleMoveInWater::enter_(ksys::act::ai::InlineParamPack* params) {
    CircleMoveFluid::enter_(params);
}

void CircleMoveInWater::leave_() {
    CircleMoveFluid::leave_();
}

void CircleMoveInWater::loadParams_() {
    CircleMoveFluid::loadParams_();
    getStaticParam(&mAllowMoveWaterDepth_s, "AllowMoveWaterDepth");
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

}  // namespace uking::ai
