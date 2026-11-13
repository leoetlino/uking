#include "Game/Actor/Action/actionSeqPunchByASEvent.h"

namespace uking::action {

SeqPunchByASEvent::SeqPunchByASEvent(const InitArg& arg) : OnetimeStopBase(arg) {}

SeqPunchByASEvent::~SeqPunchByASEvent() = default;

bool SeqPunchByASEvent::init_(sead::Heap* heap) {
    return OnetimeStopBase::init_(heap);
}

void SeqPunchByASEvent::enter_(ksys::act::ai::InlineParamPack* params) {
    OnetimeStopBase::enter_(params);
}

void SeqPunchByASEvent::leave_() {
    OnetimeStopBase::leave_();
}

void SeqPunchByASEvent::loadParams_() {
    StopBase::loadParams_();
    getStaticParam(&mASName_s, "ASName");
    getStaticParam(&mAttackIntensity_s, "AttackIntensity");
    getStaticParam(&mIsHammer_s, "IsHammer");
    getStaticParam(&mASName_s, "ASName");
}

void SeqPunchByASEvent::calc_() {
    OnetimeStopBase::calc_();
}

}  // namespace uking::action
