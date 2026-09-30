#include "KingSystem/Game/Area/Action/actionAreaHorseSpeedLimitAction.h"

namespace ksys::game {

AreaHorseSpeedLimitAction::AreaHorseSpeedLimitAction(const InitArg& arg) : AreaActionBase(arg) {}

AreaHorseSpeedLimitAction::~AreaHorseSpeedLimitAction() = default;

bool AreaHorseSpeedLimitAction::init_(sead::Heap* heap) {
    return AreaActionBase::init_(heap);
}

}  // namespace ksys::game
