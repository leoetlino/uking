#include "KingSystem/Game/Horse/Action/actionHorseSwimBase.h"

namespace ksys::game {

HorseSwimBase::HorseSwimBase(const InitArg& arg) : ksys::act::ai::Action(arg) {}

HorseSwimBase::~HorseSwimBase() = default;

bool HorseSwimBase::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void HorseSwimBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void HorseSwimBase::leave_() {
    ksys::act::ai::Action::leave_();
}

void HorseSwimBase::loadParams_() {}

void HorseSwimBase::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace ksys::game
