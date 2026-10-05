#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace ksys::game {

AreaActionBase::AreaActionBase(const InitArg& arg)
    : ksys::act::ai::Action(arg), ActorObserver(this) {}

void AreaActionBase::enter_(ksys::act::ai::InlineParamPack* params) {
    enterAndResetContactLayersSent();
}

void AreaActionBase::calc_() {
    ActorObserverBase::calc();
}

bool AreaActionBase::handleMessage_(const Message& message) {
    return ActorObserverBase::handleMessage(&message);
}

}  // namespace ksys::game
