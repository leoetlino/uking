#include "Game/Actor/AI/aiCloseAttack.h"

namespace uking::ai {

CloseAttack::CloseAttack(const InitArg& arg) : ksys::act::ai::Ai(arg) {}

CloseAttack::~CloseAttack() = default;

void CloseAttack::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Ai::enter_(params);
}

void CloseAttack::leave_() {
    ksys::act::ai::Ai::leave_();
}

void CloseAttack::loadParams_() {
    getStaticParam(&mCloseRadius_s, "CloseRadius");
    getStaticParam(&mWeaponIdx_s, "WeaponIdx");
    getStaticParam(&mIsIgnoreSmallHit_s, "IsIgnoreSmallHit");
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

}  // namespace uking::ai
