#include "Game/Actor/Action/actionSearch.h"

namespace uking::action {

Search::Search(const InitArg& arg) : OnetimeStopBase(arg) {}

Search::~Search() = default;

void Search::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void Search::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mNoChangeTime_s, "NoChangeTime");
}

void Search::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
