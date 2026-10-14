#include "KingSystem/ActorSystem/actionUpdateDataByGetDemoAction.h"

namespace ksys::act::ai {

UpdateDataByGetDemoAction::UpdateDataByGetDemoAction(const InitArg& arg) : Action(arg) {}

UpdateDataByGetDemoAction::~UpdateDataByGetDemoAction() = default;

bool UpdateDataByGetDemoAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void UpdateDataByGetDemoAction::loadParams_() {}

}  // namespace ksys::act::ai
