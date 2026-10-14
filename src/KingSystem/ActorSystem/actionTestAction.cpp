#include "KingSystem/ActorSystem/actionTestAction.h"

namespace ksys::act::ai {

TestAction::TestAction(const InitArg& arg) : Action(arg) {}

TestAction::~TestAction() = default;

bool TestAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void TestAction::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void TestAction::leave_() {
    Action::leave_();
}

void TestAction::loadParams_() {
    getDynamicParam(&mFlag_d, "Flag");
    getDynamicParam(&mName_d, "Name");
}

void TestAction::calc_() {
    Action::calc_();
}

}  // namespace ksys::act::ai
