#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionFreezedInIce.h"

namespace uking::action {

class FreezedInIceWeapon : public ksys::game::FreezedInIce {
    SEAD_RTTI_OVERRIDE(FreezedInIceWeapon, ksys::game::FreezedInIce)
public:
    explicit FreezedInIceWeapon(const InitArg& arg);
    ~FreezedInIceWeapon() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
};

}  // namespace uking::action
