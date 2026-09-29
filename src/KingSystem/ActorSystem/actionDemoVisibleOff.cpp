#include "KingSystem/ActorSystem/actionDemoVisibleOff.h"

namespace ksys::act::ai {

DemoVisibleOff::DemoVisibleOff(const InitArg& arg) : Action(arg) {}

DemoVisibleOff::~DemoVisibleOff() = default;

void DemoVisibleOff::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void DemoVisibleOff::leave_() {
    Action::leave_();
}

}  // namespace ksys::act::ai
