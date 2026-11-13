#pragma once

#include "Game/Actor/Action/actionGetItemBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class GetWeaponEquip : public GetItemBase {
    SEAD_RTTI_OVERRIDE(GetWeaponEquip, GetItemBase)
public:
    explicit GetWeaponEquip(const InitArg& arg);

    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
    void calc_() override;
};

}  // namespace uking::action
