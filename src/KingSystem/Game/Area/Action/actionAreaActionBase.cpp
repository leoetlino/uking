#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace ksys::game {

AreaActionBase::AreaActionBase(const InitArg& arg)
    : ksys::act::ai::Action(arg), ActorObserver(this) {}

AreaActionBase::~AreaActionBase() = default;

void AreaActionBase::enter_(ksys::act::ai::InlineParamPack* params) {
    enterAndResetContactLayersSent();
}

bool AreaActionBase::handleMessage_(const Message& message) {
    return ActorObserverBase::handleMessage(&message);
}

void AreaActionBase::calc_() {
    ActorObserverBase::calc();
}

}  // namespace ksys::game
