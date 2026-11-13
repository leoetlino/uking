#include "Game/Actor/Player/Action/actionPlayerIceBlockRemove.h"

namespace uking::action {

PlayerIceBlockRemove::PlayerIceBlockRemove(const InitArg& arg) : PlayerBase(arg) {}

PlayerIceBlockRemove::~PlayerIceBlockRemove() = default;

void PlayerIceBlockRemove::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerIceBlockRemove::leave_() {
    PlayerBase::leave_();
}

void PlayerIceBlockRemove::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
