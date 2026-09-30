#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace uking::action {

class ShelterFromRain : public ksys::game::AreaActionBase {
    SEAD_RTTI_OVERRIDE(ShelterFromRain, ksys::game::AreaActionBase)
public:
    explicit ShelterFromRain(const InitArg& arg);
    ~ShelterFromRain() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // map_unit_param at offset 0x38
    const int* mShelterFromRainTagType_m{};
};

}  // namespace uking::action
