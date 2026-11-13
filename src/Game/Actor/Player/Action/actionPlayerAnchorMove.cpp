#include "Game/Actor/Player/Action/actionPlayerAnchorMove.h"

namespace uking::action {

PlayerAnchorMove::PlayerAnchorMove(const InitArg& arg) : PlayerDestinationMoveBase(arg) {}

PlayerAnchorMove::~PlayerAnchorMove() = default;

bool PlayerAnchorMove::init_(sead::Heap* heap) {
    return PlayerDestinationMoveBase::init_(heap);
}

void PlayerAnchorMove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerDestinationMoveBase::enter_(params);
}

void PlayerAnchorMove::leave_() {
    PlayerDestinationMoveBase::leave_();
}

void PlayerAnchorMove::loadParams_() {
    PlayerDestinationMoveBase::loadParams_();
    getDynamicParam(&mUniqueName_d, "UniqueName");
    getDynamicParam(&mAnchorName_d, "AnchorName");
}

void PlayerAnchorMove::calc_() {
    PlayerDestinationMoveBase::calc_();
}

}  // namespace uking::action
