#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Horse/Action/actionHorseNavMeshMoveBase.h"

namespace uking::action {

class AnimalNavMeshMove : public HorseNavMeshMoveBase {
    SEAD_RTTI_OVERRIDE(AnimalNavMeshMove, HorseNavMeshMoveBase)
public:
    explicit AnimalNavMeshMove(const InitArg& arg);
    ~AnimalNavMeshMove() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
