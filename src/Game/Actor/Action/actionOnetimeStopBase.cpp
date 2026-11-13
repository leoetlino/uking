#include "Game/Actor/Action/actionOnetimeStopBase.h"

namespace uking::action {

OnetimeStopBase::OnetimeStopBase(const InitArg& arg) : StopBase(arg) {}

void OnetimeStopBase::enter_(ksys::act::ai::InlineParamPack* params) {
    StopBase::enter_(params);
}

void OnetimeStopBase::calc_() {
    StopBase::calc_();
}

}  // namespace uking::action
