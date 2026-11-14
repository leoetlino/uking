#include "KingSystem/ActorSystem/actionSimpleASPlayActionBase.h"

namespace ksys::act::ai {

SimpleASPlayActionBase::SimpleASPlayActionBase(const InitArg& arg) : Action(arg) {}

SimpleASPlayActionBase::~SimpleASPlayActionBase() = default;

bool SimpleASPlayActionBase::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void SimpleASPlayActionBase::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void SimpleASPlayActionBase::leave_() {
    Action::leave_();
}

void SimpleASPlayActionBase::loadParams_() {}

void SimpleASPlayActionBase::calc_() {
    Action::calc_();
}

}  // namespace ksys::act::ai
