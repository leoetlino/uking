#include "KingSystem/Game/Area/Action/actionFireObserveBase.h"

namespace ksys::game {

FireObserveBase::FireObserveBase(const InitArg& arg) : ksys::act::ai::Action(arg) {}

FireObserveBase::~FireObserveBase() = default;

void FireObserveBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void FireObserveBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace ksys::game
