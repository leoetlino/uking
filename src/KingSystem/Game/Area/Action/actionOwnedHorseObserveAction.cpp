#include "KingSystem/Game/Area/Action/actionOwnedHorseObserveAction.h"

namespace ksys::game {

OwnedHorseObserveAction::OwnedHorseObserveAction(const InitArg& arg) : AreaActionBase(arg) {}

OwnedHorseObserveAction::~OwnedHorseObserveAction() = default;

bool OwnedHorseObserveAction::init_(sead::Heap* heap) {
    return AreaActionBase::init_(heap);
}

void OwnedHorseObserveAction::enter_(ksys::act::ai::InlineParamPack* params) {
    AreaActionBase::enter_(params);
}

void OwnedHorseObserveAction::loadParams_() {
    getMapUnitParam(&mSaveFlag_m, "SaveFlag");
}

void OwnedHorseObserveAction::calc_() {
    AreaActionBase::calc_();
}

}  // namespace ksys::game
