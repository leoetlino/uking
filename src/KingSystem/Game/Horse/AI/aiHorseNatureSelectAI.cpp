#include "KingSystem/Game/Horse/AI/aiHorseNatureSelectAI.h"

namespace ksys::game {

HorseNatureSelectAI::HorseNatureSelectAI(const InitArg& arg) : ksys::act::ai::Ai(arg) {}

HorseNatureSelectAI::~HorseNatureSelectAI() = default;

bool HorseNatureSelectAI::init_(sead::Heap* heap) {
    return ksys::act::ai::Ai::init_(heap);
}

void HorseNatureSelectAI::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Ai::enter_(params);
}

void HorseNatureSelectAI::leave_() {
    ksys::act::ai::Ai::leave_();
}

void HorseNatureSelectAI::loadParams_() {}

}  // namespace ksys::game
