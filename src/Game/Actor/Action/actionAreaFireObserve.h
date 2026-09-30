#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionFireObserveBase.h"

namespace uking::action {

class AreaFireObserve : public ksys::game::FireObserveBase {
    SEAD_RTTI_OVERRIDE(AreaFireObserve, ksys::game::FireObserveBase)
public:
    explicit AreaFireObserve(const InitArg& arg);

protected:
};

}  // namespace uking::action
