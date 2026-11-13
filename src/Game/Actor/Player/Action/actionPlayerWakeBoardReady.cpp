#include "Game/Actor/Player/Action/actionPlayerWakeBoardReady.h"

namespace uking::action {

PlayerWakeBoardReady::PlayerWakeBoardReady(const InitArg& arg) : PlayerBase(arg) {}

PlayerWakeBoardReady::~PlayerWakeBoardReady() = default;

void PlayerWakeBoardReady::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerWakeBoardReady::leave_() {
    PlayerBase::leave_();
}

void PlayerWakeBoardReady::loadParams_() {
    getDynamicParam(&mCreateSelf_d, "CreateSelf");
    getDynamicParam(&mUniqueName_d, "UniqueName");
}

void PlayerWakeBoardReady::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
