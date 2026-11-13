#include "Game/Actor/Action/actionDemoNoAnimDrivenTurn.h"

namespace uking::action {

DemoNoAnimDrivenTurn::DemoNoAnimDrivenTurn(const InitArg& arg) : ForkTurnBase(arg) {}

DemoNoAnimDrivenTurn::~DemoNoAnimDrivenTurn() = default;

bool DemoNoAnimDrivenTurn::init_(sead::Heap* heap) {
    return ForkTurnBase::init_(heap);
}

void DemoNoAnimDrivenTurn::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkTurnBase::enter_(params);
}

void DemoNoAnimDrivenTurn::leave_() {
    ForkTurnBase::leave_();
}

void DemoNoAnimDrivenTurn::loadParams_() {
    ForkTurnBase::loadParams_();
    getDynamicParam(&mObjectId_d, "ObjectId");
    getDynamicParam(&mActorName_d, "ActorName");
    getDynamicParam(&mUniqueName_d, "UniqueName");
}

void DemoNoAnimDrivenTurn::calc_() {
    ForkTurnBase::calc_();
}

}  // namespace uking::action
