#include "Game/Actor/Action/actionSmallDamageBackward.h"

namespace uking::action {

SmallDamageBackward::SmallDamageBackward(const InitArg& arg) : KnockBackBackwardBase(arg) {}

SmallDamageBackward::~SmallDamageBackward() = default;

bool SmallDamageBackward::init_(sead::Heap* heap) {
    return KnockBackBackwardBase::init_(heap);
}

void SmallDamageBackward::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackBackwardBase::enter_(params);
}

void SmallDamageBackward::leave_() {
    KnockBackBackwardBase::leave_();
}

void SmallDamageBackward::loadParams_() {
    KnockBackBackwardBase::loadParams_();
    getStaticParam(&mIsReStartASByDamage_s, "IsReStartASByDamage");
    getStaticParam(&mASName_s, "ASName");
}

void SmallDamageBackward::calc_() {
    KnockBackBackwardBase::calc_();
}

}  // namespace uking::action
