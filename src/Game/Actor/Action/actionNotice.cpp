#include "Game/Actor/Action/actionNotice.h"

namespace uking::action {

Notice::Notice(const InitArg& arg) : OnetimeStopBase(arg) {}

void Notice::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

}  // namespace uking::action
