#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace ksys::snd {

class SoundShieldingArea;

class SoundShieldingAreaTagAction : public ksys::game::AreaActionBase {
    SEAD_RTTI_OVERRIDE(SoundShieldingAreaTagAction, ksys::game::AreaActionBase)
public:
    explicit SoundShieldingAreaTagAction(const InitArg& arg);
    ~SoundShieldingAreaTagAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // map_unit_param at offset 0x38
    const float* mMerginDistance_m{};
    // map_unit_param at offset 0x40
    const bool* mIsShieldChemicalWind_m{};
    sead::Buffer<ksys::game::AreaContactLayerEntry> mContactLayers;
    float mAreaContactDepths[16]{};
    float mShieldingRate{};
    int mShieldingRateAliveFrames{};
    SoundShieldingArea* mShieldingArea{};
};
KSYS_CHECK_SIZE_NX150(SoundShieldingAreaTagAction, 0xa8);

}  // namespace ksys::snd
