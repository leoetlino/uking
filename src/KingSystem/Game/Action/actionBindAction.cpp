#include "KingSystem/Game/Action/actionBindAction.h"

namespace ksys::game {

BindAction::BindAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

BindAction::~BindAction() = default;

void BindAction::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void BindAction::leave_() {
    ksys::act::ai::Action::leave_();
}

void BindAction::loadParams_() {}

void BindAction::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace ksys::game
