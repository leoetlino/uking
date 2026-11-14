#include "KingSystem/ActorSystem/actionSimpleASPlayAction.h"

namespace ksys::act::ai {

SimpleASPlayAction::SimpleASPlayAction(const InitArg& arg) : SimpleASPlayActionBase(arg) {}

SimpleASPlayAction::~SimpleASPlayAction() = default;

bool SimpleASPlayAction::init_(sead::Heap* heap) {
    return SimpleASPlayActionBase::init_(heap);
}

void SimpleASPlayAction::enter_(InlineParamPack* params) {
    SimpleASPlayActionBase::enter_(params);
}

void SimpleASPlayAction::leave_() {
    SimpleASPlayActionBase::leave_();
}

void SimpleASPlayAction::loadParams_() {
    SimpleASPlayActionBase::loadParams_();
    getDynamicParam(&mASSlot_d, "ASSlot");
    getDynamicParam(&mSequenceBank_d, "SequenceBank");
    getDynamicParam(&mIsIgnoreSame_d, "IsIgnoreSame");
    getDynamicParam(&mIsChangeable_d, "IsChangeable");
    getDynamicParam(&mASName_d, "ASName");
    getDynamicParam(&mDemoASName_d, "DemoASName");
}

void SimpleASPlayAction::calc_() {
    SimpleASPlayActionBase::calc_();
}

}  // namespace ksys::act::ai
