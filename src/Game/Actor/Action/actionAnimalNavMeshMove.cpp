#include "Game/Actor/Action/actionAnimalNavMeshMove.h"

namespace uking::action {

AnimalNavMeshMove::AnimalNavMeshMove(const InitArg& arg) : HorseNavMeshMoveBase(arg) {}

AnimalNavMeshMove::~AnimalNavMeshMove() = default;

bool AnimalNavMeshMove::init_(sead::Heap* heap) {
    return HorseNavMeshMoveBase::init_(heap);
}

void AnimalNavMeshMove::enter_(ksys::act::ai::InlineParamPack* params) {
    HorseNavMeshMoveBase::enter_(params);
}

void AnimalNavMeshMove::leave_() {
    HorseNavMeshMoveBase::leave_();
}

void AnimalNavMeshMove::loadParams_() {
    HorseNavMeshMoveBase::loadParams_();
}

void AnimalNavMeshMove::calc_() {
    HorseNavMeshMoveBase::calc_();
}

}  // namespace uking::action
