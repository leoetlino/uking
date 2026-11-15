#include "Game/Actor/Action/actionForkSetEndState.h"

namespace uking::action {

ForkSetEndState::ForkSetEndState(const InitArg& arg) : ksys::act::ai::Action(arg) {}

ForkSetEndState::~ForkSetEndState() = default;

bool ForkSetEndState::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void ForkSetEndState::enter_(ksys::act::ai::InlineParamPack* params) {
    if (*mIsChangeable_s)
        mFlags.set(Flag::Changeable);
}

void ForkSetEndState::leave_() {
    ksys::act::ai::Action::leave_();
}

void ForkSetEndState::loadParams_() {
    getStaticParam(&mEndState_s, "EndState");
    getStaticParam(&mIsChangeable_s, "IsChangeable");
}

void ForkSetEndState::calc_() {
    ksys::act::ai::Action::calc_();
}

void ForkSetEndState::setEndState() {
    switch (*mEndState_s) {
    case 0:
        setFinished();
        break;
    case 1:
        setFailed();
        break;
    case 2:
        mFlags.set(ksys::act::ai::ActionBase::Flag::Changeable);
        break;
    }
}

}  // namespace uking::action
