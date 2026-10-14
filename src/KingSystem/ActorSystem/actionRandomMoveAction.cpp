#include "KingSystem/ActorSystem/actionRandomMoveAction.h"

namespace ksys::act::ai {

RandomMoveAction::RandomMoveAction(const InitArg& arg) : Action(arg) {}

RandomMoveAction::~RandomMoveAction() = default;

void RandomMoveAction::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void RandomMoveAction::leave_() {
    Action::leave_();
}

void RandomMoveAction::loadParams_() {
    getStaticParam(&mIsSuccessWhenGoalReached_s, "IsSuccessWhenGoalReached");
}

void RandomMoveAction::calc_() {
    Action::calc_();
}

}  // namespace ksys::act::ai
