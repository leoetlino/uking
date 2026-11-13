#include "KingSystem/Game/Horse/Action/actionHorseSwimAction.h"

namespace ksys::game {

HorseSwimAction::HorseSwimAction(const InitArg& arg) : HorseSwimBase(arg) {}

HorseSwimAction::~HorseSwimAction() = default;

bool HorseSwimAction::init_(sead::Heap* heap) {
    return HorseSwimBase::init_(heap);
}

void HorseSwimAction::enter_(ksys::act::ai::InlineParamPack* params) {
    HorseSwimBase::enter_(params);
}

void HorseSwimAction::leave_() {
    HorseSwimBase::leave_();
}

void HorseSwimAction::loadParams_() {
    HorseSwimBase::loadParams_();
    getStaticParam(&mLandSearchRadius_s, "LandSearchRadius");
    getStaticParam(&mLandSearchNormalCos_s, "LandSearchNormalCos");
    getStaticParam(&mLandSearchMinArea_s, "LandSearchMinArea");
    getStaticParam(&mLandSearchIntervalFrames_s, "LandSearchIntervalFrames");
    getStaticParam(&mResolvePenetrationRadiusScale_s, "ResolvePenetrationRadiusScale");
    getStaticParam(&mResolvePenetrationSearchRadius_s, "ResolvePenetrationSearchRadius");
}

void HorseSwimAction::calc_() {
    HorseSwimBase::calc_();
}

}  // namespace ksys::game
