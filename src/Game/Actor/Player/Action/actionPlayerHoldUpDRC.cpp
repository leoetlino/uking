#include "Game/Actor/Player/Action/actionPlayerHoldUpDRC.h"

namespace uking::action {

PlayerHoldUpDRC::PlayerHoldUpDRC(const InitArg& arg) : PlayerBase(arg) {}

PlayerHoldUpDRC::~PlayerHoldUpDRC() = default;

void PlayerHoldUpDRC::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerHoldUpDRC::leave_() {
    PlayerBase::leave_();
}

void PlayerHoldUpDRC::loadParams_() {
    getDynamicParam(&mIsContinued_d, "IsContinued");
    getDynamicParam(&mASName_d, "ASName");
}

void PlayerHoldUpDRC::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
