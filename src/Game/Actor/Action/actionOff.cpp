#include "Game/Actor/Action/actionOff.h"

namespace uking::action {

Off::Off(const InitArg& arg) : act::ActionEx(arg) {}

Off::~Off() = default;

bool Off::init_(sead::Heap* heap) {
    return act::ActionEx::init_(heap);
}

void Off::enter_(ksys::act::ai::InlineParamPack* params) {
    act::ActionEx::enter_(params);
}

void Off::leave_() {
    act::ActionEx::leave_();
}

void Off::loadParams_() {
    getStaticParam(&mLinkTagType_s, "LinkTagType");
    getStaticParam(&mTargetIdx_s, "TargetIdx");
    getStaticParam(&mSeqBankIdx_s, "SeqBankIdx");
    getStaticParam(&mOffWaitRevival_s, "OffWaitRevival");
    getStaticParam(&mIsIgnoreSame_s, "IsIgnoreSame");
    getStaticParam(&mASName_s, "ASName");
}

void Off::calc_() {
    if (isFinishedAS(*mTargetIdx_s, *mSeqBankIdx_s))
        setFinished();
}

}  // namespace uking::action
