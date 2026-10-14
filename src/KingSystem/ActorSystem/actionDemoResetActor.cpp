#include "KingSystem/ActorSystem/actionDemoResetActor.h"

namespace ksys::act::ai {

DemoResetActor::DemoResetActor(const InitArg& arg) : Action(arg) {}

DemoResetActor::~DemoResetActor() = default;

bool DemoResetActor::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void DemoResetActor::loadParams_() {
    getDynamicParam(&mActorName_d, "ActorName");
}

}  // namespace ksys::act::ai
