#include "Game/Actor/Action/actionKnockBackShockWithAS.h"

namespace uking::action {

KnockBackShockWithAS::KnockBackShockWithAS(const InitArg& arg) : SimpleKnockBackShock(arg) {}

KnockBackShockWithAS::~KnockBackShockWithAS() = default;

bool KnockBackShockWithAS::init_(sead::Heap* heap) {
    return SimpleKnockBackShock::init_(heap);
}

void KnockBackShockWithAS::enter_(ksys::act::ai::InlineParamPack* params) {
    SimpleKnockBackShock::enter_(params);
}

void KnockBackShockWithAS::leave_() {
    SimpleKnockBackShock::leave_();
}

void KnockBackShockWithAS::loadParams_() {
    SimpleKnockBackShock::loadParams_();
    getStaticParam(&mASName_s, "ASName");
}

void KnockBackShockWithAS::calc_() {
    SimpleKnockBackShock::calc_();
}

}  // namespace uking::action
