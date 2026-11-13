#include "Game/Actor/Action/actionGiantBattleCloseMoveAction.h"

namespace uking::action {

GiantBattleCloseMoveAction::GiantBattleCloseMoveAction(const InitArg& arg)
    : BattleCloseMoveAction(arg) {}

GiantBattleCloseMoveAction::~GiantBattleCloseMoveAction() = default;

bool GiantBattleCloseMoveAction::init_(sead::Heap* heap) {
    return BattleCloseMoveAction::init_(heap);
}

void GiantBattleCloseMoveAction::enter_(ksys::act::ai::InlineParamPack* params) {
    BattleCloseMoveAction::enter_(params);
}

void GiantBattleCloseMoveAction::leave_() {
    BattleCloseMoveAction::leave_();
}

void GiantBattleCloseMoveAction::loadParams_() {
    AvoidingCloseMoveActionBase::loadParams_();
    getStaticParam(&mVibrationPower_s, "VibrationPower");
}

void GiantBattleCloseMoveAction::calc_() {
    BattleCloseMoveAction::calc_();
}

}  // namespace uking::action
