#include "Game/Actor/Action/actionGolemRepairParts.h"

namespace uking::action {

GolemRepairParts::GolemRepairParts(const InitArg& arg) : OnetimeStopBase(arg) {}

GolemRepairParts::~GolemRepairParts() = default;

bool GolemRepairParts::init_(sead::Heap* heap) {
    return OnetimeStopBase::init_(heap);
}

void GolemRepairParts::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void GolemRepairParts::leave_() {
    OnetimeStopBase::leave_();
}

void GolemRepairParts::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mASName_s, "ASName");
    getStaticParam(&mTgtBodyName_s, "TgtBodyName");
    getStaticParam(&mChmObjectName_s, "ChmObjectName");
    // FIXME: CALL sub_71005E1BE8 @ 0x71005e1be8
    // FIXME: CALL sub_71005E1BE8 @ 0x71005e1be8
    getAITreeVariable(&mGolemChemicalController_a, "GolemChemicalController");
}

void GolemRepairParts::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
