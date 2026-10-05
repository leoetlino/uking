#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"
#include "KingSystem/Sound/sndReverbArea.h"

namespace ksys::snd {

class SoundReverbAreaTagAction : public ksys::game::AreaActionBase, public ReverbArea {
    SEAD_RTTI_OVERRIDE(SoundReverbAreaTagAction, ksys::game::AreaActionBase)
public:
    explicit SoundReverbAreaTagAction(const InitArg& arg);
    ~SoundReverbAreaTagAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // map_unit_param at offset 0x70
    const float* mReverbSendAdd_m{};
    // map_unit_param at offset 0x78
    const float* mReverbTimeAdd_m{};
    // map_unit_param at offset 0x80
    const float* mEarlyReflectionFeedbackAdd_m{};
    // map_unit_param at offset 0x88
    const float* mRoomHfAdd_m{};
    // map_unit_param at offset 0x90
    const float* mReverbAdd_m{};
    // map_unit_param at offset 0x98
    const float* mMerginDistance_m{};
    sead::Buffer<ksys::game::AreaContactLayerEntry> mContactLayers;
    float mAreaContactDepths[32];
    bool mUseCachedParams{};
    float mReverbSendAddCache{};
    float mReverbTimeAddCache{};
    float mEarlyReflectionFeedbackAddCache{};
    float mRoomHfAddCache{};
    float mReverbAddCache{};
    float mMerginDistanceCache{};
};
KSYS_CHECK_SIZE_NX150(SoundReverbAreaTagAction, 0x150);

}  // namespace ksys::snd
