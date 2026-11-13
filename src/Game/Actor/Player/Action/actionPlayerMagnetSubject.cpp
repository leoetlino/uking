#include "Game/Actor/Player/Action/actionPlayerMagnetSubject.h"

namespace uking::action {

PlayerMagnetSubject::PlayerMagnetSubject(const InitArg& arg) : PlayerBase(arg) {}

void PlayerMagnetSubject::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerMagnetSubject::leave_() {
    PlayerBase::leave_();
}

void PlayerMagnetSubject::loadParams_() {
    getStaticParam(&mDRCEnergy_s, "DRCEnergy");
}

void PlayerMagnetSubject::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
