#include "Game/Actor/Action/actionForkAlwaysTurn.h"

namespace uking::action {

ForkAlwaysTurn::ForkAlwaysTurn(const InitArg& arg) : ForkTurnBase(arg) {}

ForkAlwaysTurn::~ForkAlwaysTurn() = default;

bool ForkAlwaysTurn::init_(sead::Heap* heap) {
    return ForkTurnBase::init_(heap);
}

void ForkAlwaysTurn::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkTurnBase::enter_(params);
}

void ForkAlwaysTurn::leave_() {
    ForkTurnBase::leave_();
}

void ForkAlwaysTurn::loadParams_() {
    ForkTurnBase::loadParams_();
    getDynamicParam(&mTargetPos_d, "TargetPos");
}

void ForkAlwaysTurn::calc_() {
    ForkTurnBase::calc_();
}

}  // namespace uking::action
