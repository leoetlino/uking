#include "KingSystem/ActorSystem/actionForceChangeAction.h"

namespace ksys::act::ai {

ForceChangeAction::ForceChangeAction(const InitArg& arg) : Action(arg) {}

ForceChangeAction::~ForceChangeAction() = default;

void ForceChangeAction::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void ForceChangeAction::leave_() {
    Action::leave_();
}

void ForceChangeAction::loadParams_() {
    getStaticParam(&mTree_s, "Tree");
}

void ForceChangeAction::calc_() {
    Action::calc_();
}

}  // namespace ksys::act::ai
