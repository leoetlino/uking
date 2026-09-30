#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace ksys::snd {

class SoundOcclusionTagAction : public uking::action::AreaActionBase {
    SEAD_RTTI_OVERRIDE(SoundOcclusionTagAction, uking::action::AreaActionBase)
public:
    explicit SoundOcclusionTagAction(const InitArg& arg);
    ~SoundOcclusionTagAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x48
    const float* mOcclusionLevel_s{};
};

}  // namespace ksys::snd
