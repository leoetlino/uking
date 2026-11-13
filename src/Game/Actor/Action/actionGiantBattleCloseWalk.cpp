#include "Game/Actor/Action/actionGiantBattleCloseWalk.h"

namespace uking::action {

GiantBattleCloseWalk::GiantBattleCloseWalk(const InitArg& arg) : GiantBattleCloseMoveAction(arg) {}

GiantBattleCloseWalk::~GiantBattleCloseWalk() = default;

bool GiantBattleCloseWalk::init_(sead::Heap* heap) {
    return GiantBattleCloseMoveAction::init_(heap);
}

void GiantBattleCloseWalk::enter_(ksys::act::ai::InlineParamPack* params) {
    GiantBattleCloseMoveAction::enter_(params);
}

void GiantBattleCloseWalk::leave_() {
    GiantBattleCloseMoveAction::leave_();
}

void GiantBattleCloseWalk::loadParams_() {
    GiantBattleCloseMoveAction::loadParams_();
}

void GiantBattleCloseWalk::calc_() {
    GiantBattleCloseMoveAction::calc_();
}

}  // namespace uking::action
