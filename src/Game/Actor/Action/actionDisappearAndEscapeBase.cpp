#include "Game/Actor/Action/actionDisappearAndEscapeBase.h"

namespace uking::action {

DisappearAndEscapeBase::DisappearAndEscapeBase(const InitArg& arg) : OnetimeStopBase(arg) {}

DisappearAndEscapeBase::~DisappearAndEscapeBase() = default;

bool DisappearAndEscapeBase::init_(sead::Heap* heap) {
    return OnetimeStopBase::init_(heap);
}

void DisappearAndEscapeBase::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void DisappearAndEscapeBase::leave_() {
    OnetimeStopBase::leave_();
}

void DisappearAndEscapeBase::loadParams_() {
    StopBase::loadParams_();
}

void DisappearAndEscapeBase::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
