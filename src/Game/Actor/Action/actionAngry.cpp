#include "Game/Actor/Action/actionAngry.h"

namespace uking::action {

Angry::Angry(const InitArg& arg) : OnetimeStopBase(arg) {}

bool Angry::init_(sead::Heap* heap) {
    return OnetimeStopBase::init_(heap);
}

void Angry::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void Angry::leave_() {
    OnetimeStopBase::leave_();
}

void Angry::loadParams_() {
    StopBase::loadParams_();
}

void Angry::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
