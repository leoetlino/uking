#include "KingSystem/ActorSystem/actionSimpleOpenMessageDialogAction.h"

namespace ksys::act::ai {

SimpleOpenMessageDialogAction::SimpleOpenMessageDialogAction(const InitArg& arg) : Action(arg) {}

SimpleOpenMessageDialogAction::~SimpleOpenMessageDialogAction() = default;

bool SimpleOpenMessageDialogAction::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void SimpleOpenMessageDialogAction::enter_(InlineParamPack* params) {
    Action::enter_(params);
}

void SimpleOpenMessageDialogAction::leave_() {
    Action::leave_();
}

void SimpleOpenMessageDialogAction::loadParams_() {
    getDynamicParam(&mMstxt_d, "Mstxt");
    getDynamicParam(&mLabel_d, "Label");
}

void SimpleOpenMessageDialogAction::calc_() {
    Action::calc_();
}

}  // namespace ksys::act::ai
