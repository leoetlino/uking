#include "Game/Actor/Action/actionBombExplode.h"

namespace uking::action {

BombExplode::BombExplode(const InitArg& arg) : act::ActionEx(arg) {}

BombExplode::~BombExplode() = default;

void BombExplode::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void BombExplode::leave_() {
    act::ActionEx::leave_();
}

void BombExplode::loadParams_() {}

void BombExplode::calc_() {
    act::ActionEx::calc_();
}

}  // namespace uking::action
