#include "Game/Actor/Action/actionGiantBattleCloseMove.h"

namespace uking::action {

GiantBattleCloseMove::GiantBattleCloseMove(const InitArg& arg) : GiantBattleCloseMoveAction(arg) {}

GiantBattleCloseMove::~GiantBattleCloseMove() = default;

bool GiantBattleCloseMove::init_(sead::Heap* heap) {
    return GiantBattleCloseMoveAction::init_(heap);
}

void GiantBattleCloseMove::enter_(ksys::act::ai::InlineParamPack* params) {
    GiantBattleCloseMoveAction::enter_(params);
}

void GiantBattleCloseMove::leave_() {
    GiantBattleCloseMoveAction::leave_();
}

void GiantBattleCloseMove::loadParams_() {
    GiantBattleCloseMoveAction::loadParams_();
}

void GiantBattleCloseMove::calc_() {
    GiantBattleCloseMoveAction::calc_();
}

}  // namespace uking::action
