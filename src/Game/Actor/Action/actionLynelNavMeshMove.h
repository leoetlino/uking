#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Horse/Action/actionHorseNavMeshMoveBase.h"

namespace uking::action {

class LynelNavMeshMove : public ksys::game::HorseNavMeshMoveBase {
    SEAD_RTTI_OVERRIDE(LynelNavMeshMove, ksys::game::HorseNavMeshMoveBase)
public:
    explicit LynelNavMeshMove(const InitArg& arg);
    ~LynelNavMeshMove() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // dynamic_param at offset 0x78
    sead::Vector3f* mTargetPos_d{};
};

}  // namespace uking::action
