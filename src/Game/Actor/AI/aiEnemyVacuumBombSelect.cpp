#include "Game/Actor/AI/aiEnemyVacuumBombSelect.h"

namespace uking::ai {

EnemyVacuumBombSelect::EnemyVacuumBombSelect(const InitArg& arg) : EnemyVacuumSelect(arg) {}

EnemyVacuumBombSelect::~EnemyVacuumBombSelect() = default;

bool EnemyVacuumBombSelect::init_(sead::Heap* heap) {
    return EnemyVacuumSelect::init_(heap);
}

void EnemyVacuumBombSelect::enter_(ksys::act::ai::InlineParamPack* params) {
    EnemyVacuumSelect::enter_(params);
}

void EnemyVacuumBombSelect::leave_() {
    EnemyVacuumSelect::leave_();
}

void EnemyVacuumBombSelect::loadParams_() {
    EnemyVacuumSelect::loadParams_();
}

}  // namespace uking::ai
