#include "KingSystem/Game/Horse/AI/aiHorseLoopTargetAndWaitAI.h"

namespace ksys::game {

HorseLoopTargetAndWaitAI::HorseLoopTargetAndWaitAI(const InitArg& arg) : HorseLoopTarget(arg) {}

HorseLoopTargetAndWaitAI::~HorseLoopTargetAndWaitAI() = default;

bool HorseLoopTargetAndWaitAI::init_(sead::Heap* heap) {
    return HorseLoopTarget::init_(heap);
}

void HorseLoopTargetAndWaitAI::enter_(ksys::act::ai::InlineParamPack* params) {
    HorseLoopTarget::enter_(params);
}

void HorseLoopTargetAndWaitAI::leave_() {
    HorseLoopTarget::leave_();
}

void HorseLoopTargetAndWaitAI::loadParams_() {
    HorseLoopTarget::loadParams_();
    getStaticParam(&mChangeWaitRate_s, "ChangeWaitRate");
    getStaticParam(&mMaxWaitTime_s, "MaxWaitTime");
    getStaticParam(&mMinWaitTime_s, "MinWaitTime");
}

}  // namespace ksys::game
