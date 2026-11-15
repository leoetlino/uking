#include "Game/Actor/Action/actionChuchuCommonDownTimer.h"

namespace uking::action {

ChuchuCommonDownTimer::ChuchuCommonDownTimer(const InitArg& arg) : ForkSetEndState(arg) {}

ChuchuCommonDownTimer::~ChuchuCommonDownTimer() = default;

bool ChuchuCommonDownTimer::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ChuchuCommonDownTimer::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ChuchuCommonDownTimer::leave_() {
    ForkSetEndState::leave_();
}

void ChuchuCommonDownTimer::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mMinWaitFrame_s, "MinWaitFrame");
    getAITreeVariable(&mChemicalChuchuCommonDownTime_a, "ChemicalChuchuCommonDownTime");
}

void ChuchuCommonDownTimer::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
