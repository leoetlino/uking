#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace ksys::game {

AreaActionBase::AreaActionBase(const InitArg& arg)
    : ksys::act::ai::Action(arg), AreaObserver(this) {}

void AreaActionBase::enter_(ksys::act::ai::InlineParamPack* params) {
    enterAndResetContactLayersSent();
}

void AreaActionBase::calc_() {
    AreaObserverBase::calc();
}

bool AreaActionBase::handleMessage_(const Message& message) {
    return AreaObserverBase::handleMessage(&message);
}

}  // namespace ksys::game
