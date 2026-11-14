#include "KingSystem/Game/Fauna/AI/aiDefEscapeAI.h"

namespace ksys::game {

DefEscapeAI::DefEscapeAI(const InitArg& arg) : ksys::act::ai::Ai(arg) {}

bool DefEscapeAI::init_(sead::Heap* heap) {
    return ksys::act::ai::Ai::init_(heap);
}

void DefEscapeAI::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Ai::enter_(params);
}

void DefEscapeAI::leave_() {
    ksys::act::ai::Ai::leave_();
}

void DefEscapeAI::loadParams_() {
    getStaticParam(&mIsEscapeFromSameActorType_s, "IsEscapeFromSameActorType");
}

}  // namespace ksys::game
