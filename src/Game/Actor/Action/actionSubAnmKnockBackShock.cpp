#include "Game/Actor/Action/actionSubAnmKnockBackShock.h"

namespace uking::action {

SubAnmKnockBackShock::SubAnmKnockBackShock(const InitArg& arg) : KnockBackShockWithAS(arg) {}

SubAnmKnockBackShock::~SubAnmKnockBackShock() = default;

bool SubAnmKnockBackShock::init_(sead::Heap* heap) {
    return KnockBackShockWithAS::init_(heap);
}

void SubAnmKnockBackShock::enter_(ksys::act::ai::InlineParamPack* params) {
    KnockBackShockWithAS::enter_(params);
}

void SubAnmKnockBackShock::leave_() {
    KnockBackShockWithAS::leave_();
}

void SubAnmKnockBackShock::loadParams_() {
    KnockBackShockWithAS::loadParams_();
    getStaticParam(&mSubASSlot_s, "SubASSlot");
    getStaticParam(&mSubAS_s, "SubAS");
    getStaticParam(&mLeaveSubAS_s, "LeaveSubAS");
}

void SubAnmKnockBackShock::calc_() {
    KnockBackShockWithAS::calc_();
}

}  // namespace uking::action
