#include "Game/Actor/AI/aiCircleMoveFluid.h"

namespace uking::ai {

CircleMoveFluid::CircleMoveFluid(const InitArg& arg) : ksys::act::ai::Ai(arg) {}

CircleMoveFluid::~CircleMoveFluid() = default;

bool CircleMoveFluid::init_(sead::Heap* heap) {
    return ksys::act::ai::Ai::init_(heap);
}

void CircleMoveFluid::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Ai::enter_(params);
}

void CircleMoveFluid::leave_() {
    ksys::act::ai::Ai::leave_();
}

void CircleMoveFluid::loadParams_() {
    getStaticParam(&mSpeed_s, "Speed");
    getStaticParam(&mRadiusX_s, "RadiusX");
    getStaticParam(&mRadiusZ_s, "RadiusZ");
    getStaticParam(&mMinRandRadiusRate_s, "MinRandRadiusRate");
    getStaticParam(&mMaxRandRadiusRate_s, "MaxRandRadiusRate");
    getStaticParam(&mAddAngleRateX_s, "AddAngleRateX");
    getStaticParam(&mAddAngleRateZ_s, "AddAngleRateZ");
    getStaticParam(&mRandRangeY_s, "RandRangeY");
    getStaticParam(&mRandRangeYOffest_s, "RandRangeYOffest");
    getStaticParam(&mLimitSpeedMoveY_s, "LimitSpeedMoveY");
    getStaticParam(&mChangeInterval_s, "ChangeInterval");
    getStaticParam(&mRandChangeInterval_s, "RandChangeInterval");
    getStaticParam(&mReverseMoveRate_s, "ReverseMoveRate");
    getStaticParam(&mIsSetSystemDeleteDistance_s, "IsSetSystemDeleteDistance");
}

}  // namespace uking::ai
