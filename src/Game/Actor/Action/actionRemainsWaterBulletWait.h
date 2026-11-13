#pragma once

#include "Game/Actor/Action/actionRemainsWaterBulletMoveBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class RemainsWaterBulletWait : public RemainsWaterBulletMoveBase {
    SEAD_RTTI_OVERRIDE(RemainsWaterBulletWait, RemainsWaterBulletMoveBase)
public:
    explicit RemainsWaterBulletWait(const InitArg& arg);
    ~RemainsWaterBulletWait() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x80
    const float* mMaxChaseAngle_s{};
    // static_param at offset 0x88
    const float* mMaxSpeed_s{};
    // static_param at offset 0x90
    const float* mChaseRate_s{};
    // map_unit_param at offset 0x98
    const float* mRemainsWaterBulletAngle_m{};
    // map_unit_param at offset 0xa0
    const sead::Vector3f* mRemainsWaterBulletOffset_m{};
};

}  // namespace uking::action
