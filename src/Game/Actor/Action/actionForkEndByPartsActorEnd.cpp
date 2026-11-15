#include "Game/Actor/Action/actionForkEndByPartsActorEnd.h"

namespace uking::action {

ForkEndByPartsActorEnd::ForkEndByPartsActorEnd(const InitArg& arg) : ForkSetEndState(arg) {}

ForkEndByPartsActorEnd::~ForkEndByPartsActorEnd() = default;

bool ForkEndByPartsActorEnd::init_(sead::Heap* heap) {
    return ForkSetEndState::init_(heap);
}

void ForkEndByPartsActorEnd::enter_(ksys::act::ai::InlineParamPack* params) {
    ForkSetEndState::enter_(params);
}

void ForkEndByPartsActorEnd::leave_() {
    ForkSetEndState::leave_();
}

void ForkEndByPartsActorEnd::loadParams_() {
    ForkSetEndState::loadParams_();
    getStaticParam(&mPartsKey_s, "PartsKey");
}

void ForkEndByPartsActorEnd::calc_() {
    ForkSetEndState::calc_();
}

}  // namespace uking::action
