#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace xlink2 {
class Handle;
}  // namespace xlink2

namespace ksys::snd {

enum class EnvSeEmitPointInsectTimeBand {
    None,
    Day,
    Night,
};

class EnvSeEmitPointInsectPlayAction : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(EnvSeEmitPointInsectPlayAction, ksys::act::ai::Action)
public:
    explicit EnvSeEmitPointInsectPlayAction(const InitArg& arg);
    ~EnvSeEmitPointInsectPlayAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    s32 mLastHour = -1;
    f32 mFadeOutTime = -1.0f;
    EnvSeEmitPointInsectTimeBand mTimeBand = EnvSeEmitPointInsectTimeBand::None;
    xlink2::Handle* mHandle{};
    u64 mEmitTick;
    bool mEmitPending{};
};
KSYS_CHECK_SIZE_NX150(EnvSeEmitPointInsectPlayAction, 0x40);

}  // namespace ksys::snd
