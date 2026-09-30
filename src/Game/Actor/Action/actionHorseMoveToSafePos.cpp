#include "Game/Actor/Action/actionHorseMoveToSafePos.h"

namespace uking::action {

HorseMoveToSafePos::HorseMoveToSafePos(const InitArg& arg) : HorseNavMeshMoveBase(arg) {}

HorseMoveToSafePos::~HorseMoveToSafePos() = default;

bool HorseMoveToSafePos::init_(sead::Heap* heap) {
    return HorseNavMeshMoveBase::init_(heap);
}

void HorseMoveToSafePos::enter_(ksys::act::ai::InlineParamPack* params) {
    HorseNavMeshMoveBase::enter_(params);
}

void HorseMoveToSafePos::leave_() {
    HorseNavMeshMoveBase::leave_();
}

void HorseMoveToSafePos::loadParams_() {
    HorseNavMeshMoveBase::loadParams_();
    getStaticParam(&mSearchRadius_s, "SearchRadius");
    getStaticParam(&mAreaThreshold_s, "AreaThreshold");
    getStaticParam(&mResolvePenetrationRadiusScale_s, "ResolvePenetrationRadiusScale");
    getStaticParam(&mResolvePenetrationSearchRadius_s, "ResolvePenetrationSearchRadius");
    getStaticParam(&mSetEndIfCurrentFaceIsSafe_s, "SetEndIfCurrentFaceIsSafe");
}

void HorseMoveToSafePos::calc_() {
    HorseNavMeshMoveBase::calc_();
}

}  // namespace uking::action
