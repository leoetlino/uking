#include "KingSystem/Game/Event/Action/actionEventInitTalkAction.h"

namespace ksys::game {

EventInitTalkAction::EventInitTalkAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

bool EventInitTalkAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void EventInitTalkAction::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void EventInitTalkAction::leave_() {
    ksys::act::ai::Action::leave_();
}

void EventInitTalkAction::loadParams_() {}

void EventInitTalkAction::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace ksys::game
