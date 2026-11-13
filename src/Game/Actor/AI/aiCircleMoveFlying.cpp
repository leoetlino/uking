#include "Game/Actor/AI/aiCircleMoveFlying.h"

namespace uking::ai {

CircleMoveFlying::CircleMoveFlying(const InitArg& arg) : CircleMoveFluid(arg) {}

CircleMoveFlying::~CircleMoveFlying() = default;

bool CircleMoveFlying::init_(sead::Heap* heap) {
    return CircleMoveFluid::init_(heap);
}

void CircleMoveFlying::enter_(ksys::act::ai::InlineParamPack* params) {
    CircleMoveFluid::enter_(params);
}

void CircleMoveFlying::leave_() {
    CircleMoveFluid::leave_();
}

void CircleMoveFlying::loadParams_() {
    CircleMoveFluid::loadParams_();
    getStaticParam(&mIsCheckSafetyAreaRadius_s, "IsCheckSafetyAreaRadius");
    getStaticParam(&mIsUseHomePos_s, "IsUseHomePos");
}

}  // namespace uking::ai
