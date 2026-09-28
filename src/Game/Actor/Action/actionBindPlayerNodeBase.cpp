#include "Game/Actor/Action/actionBindPlayerNodeBase.h"
#include "Game/Actor/Action/actionBindPlayerNodeEx.h"

namespace uking::action {

[[gnu::noinline]] BindPlayerNodeBase::BindPlayerNodeBase(const InitArg& arg) : ActionEx(arg) {}

BindPlayerNodeBase::~BindPlayerNodeBase() = default;

void BindPlayerNodeBase::enter_(ksys::act::ai::InlineParamPack* params) {
    ActionEx::enter_(params);
}

void BindPlayerNodeBase::leave_() {
    ActionEx::leave_();
}

void BindPlayerNodeBase::loadParams_() {
    getStaticParam(&mBoneName_s, "BoneName");
    getStaticParam(&mPosOffset_s, "PosOffset");
    getStaticParam(&mRotOffsetXyz_s, "RotOffsetXyz");
}

void BindPlayerNodeBase::calc_() {
    if (isFinishedAS(0, 0))
        setFinished();
}

BindPlayerNodeEx::BindPlayerNodeEx(const InitArg& arg) : BindPlayerNodeBase(arg) {}

}  // namespace uking::action
