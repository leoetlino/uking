#include "Game/Actor/Player/Action/actionPlayerDestinationTurnStarter.h"

namespace uking::action {

PlayerDestinationTurnStarter::PlayerDestinationTurnStarter(const InitArg& arg) : PlayerBase(arg) {}

PlayerDestinationTurnStarter::~PlayerDestinationTurnStarter() = default;

bool PlayerDestinationTurnStarter::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerDestinationTurnStarter::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerDestinationTurnStarter::leave_() {
    PlayerBase::leave_();
}

void PlayerDestinationTurnStarter::loadParams_() {}

void PlayerDestinationTurnStarter::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
