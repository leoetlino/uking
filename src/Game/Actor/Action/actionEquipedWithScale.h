#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Action/actionEquipedAction.h"

namespace uking::action {

class EquipedWithScale : public ksys::game::EquipedAction {
    SEAD_RTTI_OVERRIDE(EquipedWithScale, ksys::game::EquipedAction)
public:
    explicit EquipedWithScale(const InitArg& arg);
    ~EquipedWithScale() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
};

}  // namespace uking::action
