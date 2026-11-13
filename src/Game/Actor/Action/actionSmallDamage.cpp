#include "Game/Actor/Action/actionSmallDamage.h"

namespace uking::action {

SmallDamage::SmallDamage(const InitArg& arg) : KnockBackNoRotBase(arg) {}

void SmallDamage::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackNoRotBase::enter_(params);
}

}  // namespace uking::action
