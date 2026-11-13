#include "Game/Actor/Action/actionAppear.h"

namespace uking::action {

Appear::Appear(const InitArg& arg) : OnetimeStopBase(arg) {}

void Appear::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

}  // namespace uking::action
