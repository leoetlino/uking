#include "Game/Actor/Player/Action/actionPlayerGrabPut.h"

namespace uking::action {

PlayerGrabPut::PlayerGrabPut(const InitArg& arg) : PlayerBase(arg) {}

void PlayerGrabPut::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerGrabPut::leave_() {
    PlayerBase::leave_();
}

void PlayerGrabPut::loadParams_() {
    getStaticParam(&mPutStartFrmae_s, "PutStartFrmae");
}

void PlayerGrabPut::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
