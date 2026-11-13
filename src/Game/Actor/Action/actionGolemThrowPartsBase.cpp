#include "Game/Actor/Action/actionGolemThrowPartsBase.h"

namespace uking::action {

GolemThrowPartsBase::GolemThrowPartsBase(const InitArg& arg) : OnetimeStopBase(arg) {}

GolemThrowPartsBase::~GolemThrowPartsBase() = default;

bool GolemThrowPartsBase::init_(sead::Heap* heap) {
    return OnetimeStopBase::init_(heap);
}

void GolemThrowPartsBase::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void GolemThrowPartsBase::leave_() {
    OnetimeStopBase::leave_();
}

void GolemThrowPartsBase::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mASName_s, "ASName");
    getStaticParam(&mTgtBodyName_s, "TgtBodyName");
    getStaticParam(&mChmObjectName_s, "ChmObjectName");
    // FIXME: CALL sub_71005E1BE8 @ 0x71005e1be8
    // FIXME: CALL sub_71005E1BE8 @ 0x71005e1be8
    getAITreeVariable(&mGolemChemicalController_a, "GolemChemicalController");
}

void GolemThrowPartsBase::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
