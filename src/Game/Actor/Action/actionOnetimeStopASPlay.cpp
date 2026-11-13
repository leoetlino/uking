#include "Game/Actor/Action/actionOnetimeStopASPlay.h"

namespace uking::action {

OnetimeStopASPlay::OnetimeStopASPlay(const InitArg& arg) : OnetimeStopBase(arg) {}

OnetimeStopASPlay::~OnetimeStopASPlay() = default;

void OnetimeStopASPlay::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void OnetimeStopASPlay::leave_() {
    OnetimeStopBase::leave_();
}

void OnetimeStopASPlay::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mIsIgnoreSame_s, "IsIgnoreSame");
    getStaticParam(&mASName_s, "ASName");
}

void OnetimeStopASPlay::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
