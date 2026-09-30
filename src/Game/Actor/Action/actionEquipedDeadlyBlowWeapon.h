#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionEquipedAction.h"

namespace uking::action {

class EquipedDeadlyBlowWeapon : public ksys::game::EquipedAction {
    SEAD_RTTI_OVERRIDE(EquipedDeadlyBlowWeapon, ksys::game::EquipedAction)
public:
    explicit EquipedDeadlyBlowWeapon(const InitArg& arg);
    ~EquipedDeadlyBlowWeapon() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
