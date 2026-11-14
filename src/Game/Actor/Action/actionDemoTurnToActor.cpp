#include "Game/Actor/Action/actionDemoTurnToActor.h"

namespace uking::action {

DemoTurnToActor::DemoTurnToActor(const InitArg& arg) : SimpleASPlayAction(arg) {}

DemoTurnToActor::~DemoTurnToActor() = default;

bool DemoTurnToActor::init_(sead::Heap* heap) {
    return SimpleASPlayAction::init_(heap);
}

void DemoTurnToActor::enter_(ksys::act::ai::InlineParamPack* params) {
    SimpleASPlayAction::enter_(params);
}

void DemoTurnToActor::leave_() {
    SimpleASPlayAction::leave_();
}

void DemoTurnToActor::loadParams_() {
    SimpleASPlayAction::loadParams_();
    getDynamicParam(&mActorName_d, "ActorName");
    getDynamicParam(&mUniqueName_d, "UniqueName");
}

void DemoTurnToActor::calc_() {
    SimpleASPlayAction::calc_();
}

}  // namespace uking::action
