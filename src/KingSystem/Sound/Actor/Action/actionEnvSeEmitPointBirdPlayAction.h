#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::snd {

enum class EnvSeEmitPointBirdType {
    Temperate,
    SubTropic,
    Tropical,
    Subarctic,
    Arctic,
    Ard,
    Wet,
    WetSubtropic,
};

class EnvSeEmitPointBirdPlayAction : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(EnvSeEmitPointBirdPlayAction, ksys::act::ai::Action)
public:
    explicit EnvSeEmitPointBirdPlayAction(const InitArg& arg);
    ~EnvSeEmitPointBirdPlayAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    float calcPlayFrequency();

    u64 mLastChirpTick;
    s64 mChirpIntervalTicks{};
    u64 mChirpHoldUntilTick;
    EnvSeEmitPointBirdType mBirdType{};
};
KSYS_CHECK_SIZE_NX150(EnvSeEmitPointBirdPlayAction, 0x40);

}  // namespace ksys::snd
