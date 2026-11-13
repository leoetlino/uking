#include "Game/Actor/Player/Action/actionPlayerBeetleSubject.h"

namespace uking::action {

PlayerBeetleSubject::PlayerBeetleSubject(const InitArg& arg) : PlayerBase(arg) {}

void PlayerBeetleSubject::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerBeetleSubject::leave_() {
    PlayerBase::leave_();
}

void PlayerBeetleSubject::loadParams_() {
    getStaticParam(&mAimRange_s, "AimRange");
}

void PlayerBeetleSubject::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
