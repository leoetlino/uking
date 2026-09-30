#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionBindAction.h"

namespace uking::action {

class GiantArmorEquip : public ksys::game::BindAction {
    SEAD_RTTI_OVERRIDE(GiantArmorEquip, ksys::game::BindAction)
public:
    explicit GiantArmorEquip(const InitArg& arg);
    ~GiantArmorEquip() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
