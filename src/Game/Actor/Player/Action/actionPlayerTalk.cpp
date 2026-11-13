#include "Game/Actor/Player/Action/actionPlayerTalk.h"

namespace uking::action {

PlayerTalk::PlayerTalk(const InitArg& arg) : PlayerBase(arg) {}

PlayerTalk::~PlayerTalk() = default;

bool PlayerTalk::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerTalk::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerTalk::leave_() {
    PlayerBase::leave_();
}

void PlayerTalk::loadParams_() {
    getDynamicParam(&mGreetingType_d, "GreetingType");
}

void PlayerTalk::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
