#include "Game/Actor/AI/aiHorseRiddenByNPC.h"

namespace uking::ai {

HorseRiddenByNPC::HorseRiddenByNPC(const InitArg& arg) : DefEscapeAI(arg) {}

HorseRiddenByNPC::~HorseRiddenByNPC() = default;

bool HorseRiddenByNPC::init_(sead::Heap* heap) {
    return DefEscapeAI::init_(heap);
}

void HorseRiddenByNPC::enter_(ksys::act::ai::InlineParamPack* params) {
    DefEscapeAI::enter_(params);
}

void HorseRiddenByNPC::leave_() {
    DefEscapeAI::leave_();
}

void HorseRiddenByNPC::loadParams_() {
    DefEscapeAI::loadParams_();
    getStaticParam(&mNavMeshCharacterScaleAtPrecise_s, "NavMeshCharacterScaleAtPrecise");
}

}  // namespace uking::ai
