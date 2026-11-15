#pragma once

#include "Game/Actor/Action/actionLevelFlyRiseLookingTargetBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class LevelFlyLookDownToTgtHeight : public LevelFlyRiseLookingTargetBase {
    SEAD_RTTI_OVERRIDE(LevelFlyLookDownToTgtHeight, LevelFlyRiseLookingTargetBase)
public:
    explicit LevelFlyLookDownToTgtHeight(const InitArg& arg);
    ~LevelFlyLookDownToTgtHeight() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
