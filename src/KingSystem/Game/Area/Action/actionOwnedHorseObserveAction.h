#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionAreaActionBase.h"

namespace ksys::game {

class OwnedHorseObserveAction : public AreaActionBase {
    SEAD_RTTI_OVERRIDE(OwnedHorseObserveAction, AreaActionBase)
public:
    explicit OwnedHorseObserveAction(const InitArg& arg);
    ~OwnedHorseObserveAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void loadParams_() override;

protected:
    void calc_() override;

    // map_unit_param at offset 0x38
    sead::SafeString mSaveFlag_m{};
};

}  // namespace ksys::game
