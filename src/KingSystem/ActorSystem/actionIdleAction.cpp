#include "KingSystem/ActorSystem/actionIdleAction.h"

namespace ksys::act::ai {

IdleAction::IdleAction(const InitArg& arg) : Action(arg) {}

IdleAction::~IdleAction() = default;

bool IdleAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void IdleAction::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void IdleAction::leave_() {
    Action::leave_();
}

void IdleAction::loadParams_() {
    getDynamicParam(&mDisablePhysics_d, "DisablePhysics");
}

void IdleAction::calc_() {
    Action::calc_();
}

}  // namespace ksys::act::ai
