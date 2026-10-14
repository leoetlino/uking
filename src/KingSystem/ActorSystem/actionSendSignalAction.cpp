#include "KingSystem/ActorSystem/actionSendSignalAction.h"

namespace ksys::act::ai {

SendSignalAction::SendSignalAction(const InitArg& arg) : Action(arg) {}

SendSignalAction::~SendSignalAction() = default;

bool SendSignalAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void SendSignalAction::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void SendSignalAction::leave_() {
    Action::leave_();
}

void SendSignalAction::loadParams_() {
    getDynamicParam(&mSignalType_d, "SignalType");
    getDynamicParam(&mValue_d, "Value");
}

void SendSignalAction::calc_() {
    Action::calc_();
}

}  // namespace ksys::act::ai
