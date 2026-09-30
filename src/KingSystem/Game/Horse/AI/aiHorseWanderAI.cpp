#include "KingSystem/Game/Horse/AI/aiHorseWanderAI.h"

namespace ksys::game {

HorseWanderAI::HorseWanderAI(const InitArg& arg) : ksys::act::ai::Ai(arg) {}

HorseWanderAI::~HorseWanderAI() = default;

void HorseWanderAI::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Ai::enter_(params);
}

void HorseWanderAI::leave_() {
    ksys::act::ai::Ai::leave_();
}

void HorseWanderAI::loadParams_() {}

}  // namespace ksys::game
