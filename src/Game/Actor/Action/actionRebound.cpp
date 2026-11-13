#include "Game/Actor/Action/actionRebound.h"

namespace uking::action {

Rebound::Rebound(const InitArg& arg) : OnetimeStopBase(arg) {}

void Rebound::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

}  // namespace uking::action
