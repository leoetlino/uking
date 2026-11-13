#include "Game/Actor/Player/Action/actionPlayerHangWallCatch.h"

namespace uking::action {

PlayerHangWallCatch::PlayerHangWallCatch(const InitArg& arg) : PlayerBase(arg) {}

void PlayerHangWallCatch::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerHangWallCatch::leave_() {
    PlayerBase::leave_();
}

void PlayerHangWallCatch::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
